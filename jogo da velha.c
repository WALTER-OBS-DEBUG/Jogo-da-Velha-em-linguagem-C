//Utilize a criatividade para este trabalho, mas obedecendo 
//as principais regras do jogo e conceitos abordados na disciplina. Bom trabalho!

//Crie um programa em C para simular o Jogo da Velha. 
//Utilize o conceito de modularização para as funções do jogo e do programa, 
//além das estruturas de dados arrays ou matrizes para representar o tabuleiro.
//Para a simulação, considere que haverá dois jogadores.Caso deseje, um deles pode ser o computador.
//Especifique a vez de cada jogador. Crie um menu para ser exibido ao final de cada partida,
//pedindo para o usuário encerrar ou continuar no jogo. Utilize as funções para verificar se um jogador venceu o jogo,
//ou seja, se foi preenchida com um símbolo, caractere ou número uma das linhas, colunas ou diagonais. 
//Os jogadores podem jogar quantas vezes quiserem, desde que informem a opção de prosseguir no menu. 
//Ao escolherem finalizar o jogo, um relatório deve ser exibido, informando os seguintes dados: 

//Quantidade de partidas jogadas
//Quantas partidas o jogador 1 venceu
//Quantas partidas o jogador 2 venceu
//A porcentagem de vitórias cada jogador

#include <stdio.h>
#define tam 3

int vez, quant_partidas=0, vitoria_jog1=0, vitoria_jog2=0;
float porcentagem1, porcentagem2;
typedef struct jogad
{
	int l, c;
}jogad;
void exibe(int tabuleiro[][tam])
{
    int l, c;
    printf("\n");
    for(l = 0 ; l < tam ; l++)
    {
        for(c = 0 ; c < tam ; c++)
        {
            if(tabuleiro[l][c] == 0)
                printf("   ");
            else
                if(tabuleiro[l][c] == 1)
                    printf(" X ");
                else
                    printf(" O ");
            if(c != (tam-1))
                printf("|");
        }
        printf("\n");
    }
    printf("\n");
} 
void zerar(int tabuleiro[][tam])
{
    int l, c;
    for(l = 0 ; l < tam ; l++)
        for(c = 0 ; c < tam ; c++)
            tabuleiro[l][c] = 0;
}
void jogar(int tabuleiro[][tam])
{
    int continua;
    zerar(tabuleiro);
    while(checaTermino(tabuleiro, vez) != 1)
    {
    	exibe(tabuleiro);
        jogada(tabuleiro);
    }
}
int checaLocal(int tabuleiro[][tam], int l, int c)
{
    if(l < 0 || l > (tam-1) || c < 0 || c > (tam-1) || tabuleiro[l][c] != 0)
        return 0;
    else
        return 1;
} 
int checaLinha(int tabuleiro[][tam])
{
    int l, c, soma;
    for(l = 0 ; l < tam ; l++)
    {
        soma=0;
        for(c = 0 ; c < tam ; c++)
            soma += tabuleiro[l][c];
        if(soma==tam || soma == (-1)*tam)
            return 1;
    }
    return 0;
} 
int checaColuna(int tabuleiro[][tam])
{
    int l, c, soma;
    for(c = 0 ; c < tam ; c++)
    {
        soma=0;
        for(l = 0 ; l < tam ; l++)
            soma += tabuleiro[l][c];
        if(soma==tam || soma == (-1)*tam)
            return 1;
    }
    return 0;
} 
int checaDiagonal(int tabuleiro[][tam])
{
    int l, diagonal_principal=0, diagonal_secundaria=0;
    for(l = 0 ; l < tam ; l++)
    {
        diagonal_principal += tabuleiro[l][l];
        diagonal_secundaria += tabuleiro[l][tam-l-1];
    }
    if(diagonal_principal==tam || diagonal_principal==(-1)*tam || diagonal_secundaria==tam || diagonal_secundaria==(-1)*tam)
       return 1; 
    return 0;
} 
int checaEmpate(int tabuleiro[][tam])
{
    int l, c;
 
    for(l = 0 ; l < tam ; l++)
        for(c = 0 ; c < tam ; c++)
            if(tabuleiro[l][c] == 0)
                return 0;
    return 1;
} 
int checaTermino(int tabuleiro[][tam], int vez)
{
    if(checaLinha(tabuleiro))
    {
    	exibe(tabuleiro);
        printf("Jogador %d venceu!\n", (vez%2)+1);
        if(((vez%2)+1)==1)
	    {
	    	vitoria_jog1++;
	    }
		else
		{
			vitoria_jog2++;
		}	
        return 1;
    }
    if(checaColuna(tabuleiro))
    {
    	exibe(tabuleiro);
        printf("Jogador %d venceu!\n\n", (vez%2)+1);
        if(((vez%2)+1)==1)
	    {
	    	vitoria_jog1++;
	    }
		else
		{
			vitoria_jog2++;
		}	
        return 1;
    }
    if(checaDiagonal(tabuleiro))
    {
    	exibe(tabuleiro);
        printf("Jogador %d venceu!\n\n", (vez%2)+1);
	        if(((vez%2)+1)==1)
	    {
	    	vitoria_jog1++;
	    }
		else
		{
			vitoria_jog2++;
		}	
        return 1;
    }
    if(checaEmpate(tabuleiro))
    {
        printf("VELHOU!\n");
        exibe(tabuleiro);
        return 1;
    }	
    return 0;
}
int menu()
{
    int op;
    printf("Jogo da Velha\n");
    printf("1 - Jogar\n");
	printf("0 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &op);
    if(op==1)
    {
    	quant_partidas++;
    	return op;
    }
    else if(op==0)
	{
		printf("\nQuantidade de partidas: %d\n", quant_partidas);
		printf("Quantidade de Vitorias do Jogador 1: %d\n", vitoria_jog1);
		printf("Quantidade de Vitorias do Jogador 2: %d\n", vitoria_jog2);
		porcentagem1=((vitoria_jog1)*100)/quant_partidas;
		porcentagem2=((vitoria_jog2)*100)/quant_partidas;
		printf("Porcentagem de Vitorias do Jogador 1: %0.1f %\n", porcentagem1);
		printf("Porcentagem de Vitorias do Jogador 2: %0.1f %\n", porcentagem2);
		exit(0);
	} 
    else
    {
        printf("Opcao invalida!\n");
    }
}
void jogada(int tabuleiro[][tam])
{
    jogad j;
    vez++;
    printf("\nJogador %d\n", (vez % 2) + 1);
    do
    {
        printf("Linha: ");
        scanf("%d", &j.l);
        j.l--; 
        printf("Coluna: ");
        scanf("%d", &j.c);
        j.c--;
        if(checaLocal(tabuleiro, j.l, j.c) == 0)
 	    	printf("Posicao invalida.\n");
    }while(checaLocal(tabuleiro, j.l, j.c) == 0);
    if(vez%2)
        tabuleiro[j.l][j.c] = -1;
    else
        tabuleiro[j.l][j.c] = 1;
    system("cls");
}
int main()
{
    int tabuleiro[tam][tam], continua;
    do
    {
    	continua=menu();
    	vez=1;
        if(continua==1)
            jogar(tabuleiro);
    }while(continua);
    return 0;
}
