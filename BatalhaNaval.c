/* Trabalho de Estrutura de Dados */
/* 1/2017 Turma B */
/* Judy Pirangi Inacio Rodrigues 16/0010438 */
/* Mateus Rocha da Silva 16/0015031 */

#include <stdio.h>
#include <stdlib.h>

int zera_matriz(int m[5][10])   /*Zera matriz(AGUA)*/
{
    int i,j;
    for(i=0; i<5; i++)
    {
        for(j=0; j<10; j++)
        {
            m[i][j]=0;
        }
    }
}
/*=====================================================================================================================================*/
int posiciona_embarcacoes(int m[5][10])
{
    int i,j,cont;
    /*Agua eh representada por 0, submarinos por 1, contratorpedeiros por 3 e navios-tanque por 4*/

    /*Coloca um navio-tanque (4 casas) no mapa*/
    srand( (unsigned)time(NULL) );
    i=(rand()%5);
    j=(rand()%10);

    if((j==9) || (j==8))      /*Evita a mesma embarcação em linhas diferentes*/
    {
        m[i][j]= 4;
        m[i][j-1]= 4;
        m[i][j-2]= 4;
        m[i][j-3]= 4;
    }

    else if((j==0) || (j==1))
    {
        m[i][j]= 4;
        m[i][j+1]= 4;
        m[i][j+2]= 4;
        m[i][j+3]= 4;
    }

    else
    {
        m[i][j]= 4;
        m[i][j-1]= 4;
        m[i][j+1]= 4;
        m[i][j+2]= 4;
    }

    /*Coloca um contratorpedeiro (3 casas) no mapa*/
    do
    {
        srand( (unsigned)time(NULL) );
        i=(rand()%5);
        j=(rand()%10);
    }
    while ((m[i][j]!=0) || (m[i][j-1]!=0) || (m[i][j+1]!=0)); /*Confere se a posicao sorteada, a anterior e a posterior estao desocupadas*/

    if(j==9)
    {
        m[i][j]= 3;
        m[i][j-1]= 3;
        m[i][j-2]= 3;
    }
    else if(j==0)
    {
        m[i][j]= 3;
        m[i][j+1]= 3;
        m[i][j+2]= 3;
    }
    else
    {
        m[i][j]= 3;
        m[i][j-1]= 3;
        m[i][j+1]= 3;
    }

    /*Coloca quatro submarinos (1 casa) no mapa*/
    for(cont=0; cont<4; cont++)
    {
        do
        {
            srand( (unsigned)time(NULL) );
            i=(rand()%5);
            j=(rand()%10);
        }
        while (m[i][j]!=0);
        m[i][j]= 1;
    }

}
/*=====================================================================================================================================*/

int main()
{
    int i,j,m1[5][10],m2[5][10],tiros=0,fim=0,m1base[5][10],m2base[5][10];
    zera_matriz(m1);
    zera_matriz(m2);
    zera_matriz(m1base);
    zera_matriz(m2base);
    posiciona_embarcacoes(m1);
    posiciona_embarcacoes(m2);

    /* Liberdade Criativa */
    printf("BEM VINDO(A) AO MAR\n\nPrepare-se para defender suas embarcacoes ou morrer tentando.\n");
    printf("Para vencer voce deve afundar todos os quatro Submarinos(1),\nas tres partes do Contratorpedeiro(333) e\nas quatro partes do Navio-Tanque(4444)\n\nE o mapa inimigo apenas mostra as embarcacoes que voce ja acertou.\n\n");
    printf("Nao esqueca que as coordenadas da area de ataque variam entre\n0 e 4 na vertical e 0 e 9 na horizontal.\n\n");
    printf("QUE A BATALHA NAVAL COMECE\n\n\n");

    do
    {

        printf("-------------------------------------------\n");
        printf("    MAPA INIMIGO\n\n");
        for(i=0; i<5; i++){
            printf(" ");
            for(j=0; j<10; j++){
                printf("%d ",m2base[i][j]);
                }
            printf("\n");
        }


        do
        {
            printf("\nJogador 1\nInforme a posicao para ataque: ");
            scanf("%d %d",&i,&j);
        }
        while ((i<0) || (i>4) || (j<0) || (j>9));

        if(m2[i][j]== 4)
        {
            printf("\nVOCE ACERTOU UM PEDACO DO NAVIO-TANQUE!");
            m2[i][j]= 0;
            m2base[i][j]= 4;
        }
        else if(m2[i][j]== 3)
        {
            printf("\nVOCE ACERTOU UM PEDACO DO CONTRATORPEDEIRO!");
            m2[i][j]= 0;
            m2base[i][j]= 3;
        }
        else if(m2[i][j]== 1)
        {
            printf("\nVOCE ACERTOU UM SUBMARINO!");
            m2[i][j]= 0;
            m2base[i][j]= 1;
        }
        else
        {
            printf("\nVoce atirou na agua");
        }
        tiros++;
        printf("\n\n");

        if(tiros>=11)  /*Usado para verificar se um jogador ganhou (se a matriz do oponente foi zerada) apenas depois de 11 tiros (quantidade minima para vencer o jogo)*/
        {
            for(i=0; i<5; i++)
            {
                for(j=0; j<10; j++)
                {
                    if (m2[i][j]!=0)
                    {
                        i=6;
                        j=11;
                    }
                }
            }
            if ((i<6) && (j<11))
            {
                printf("JOGADOR 1 VENCEU!");
                printf("\n");
                return 0;
            }
        }
        printf("-------------------------------------------\n");
        printf("    MAPA INIMIGO\n\n");
        for(i=0; i<5; i++){
            printf(" ");
            for(j=0; j<10; j++){
                printf("%d ",m1base[i][j]);
            }
            printf("\n");
        }


        do
        {
            printf("\nJogador 2\nInforme a posicao para ataque: ");
            scanf("%d %d",&i,&j);
        }
        while ((i<0) || (i>4) || (j<0) || (j>9));



        if(m1[i][j]== 4)
        {
            printf("\nVOCE ACERTOU UM PEDACO DO NAVIO-TANQUE!");
            m1[i][j]= 0;
            m1base[i][j]= 4;
        }
        else if(m1[i][j]== 3)
        {
            printf("\nVOCE ACERTOU UM PEDACO DO CONTRATORPEDEIRO!");
            m1[i][j]= 0;
            m1base[i][j]= 3;
        }
        else if(m1[i][j]== 1)
        {
            printf("\nVOCE ACERTOU UM SUBMARINO!");
            m1[i][j]= 0;
            m1base[i][j]= 1;
        }
        else
        {
            printf("\nVoce atirou na agua");
        }
        printf("\n\n");

        if (tiros>11)
        {
            for(i=0; i<5; i++)
            {
                for(j=0; j<10; j++)
                {
                    if (m1[i][j]!=0)
                    {
                        i=6;
                        j=11;
                    }
                }
            }
            if ((i<6) && (j<11))
            {
                printf("JOGADOR 2 VENCEU!");
                printf("\n");
                return 0;
            }
        }

    }
    while(fim == 0);
}
