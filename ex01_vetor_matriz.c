#include <stdio.h>

int main()
{
    int v[10], m[3][4], i, j;

    printf("Informe 10 valores para o vetor:\n\n");
    for(i=0; i<10; i++)
    {
        scanf("%d",&v[i]);
    }
    printf("\n Seu vetor: ");
    for(i=0; i<10; i++)
    {
        printf("%d ",v[i]);
    }

    printf("\n\nInforme 12 valores para a matriz:\n\n");
    for(i=0; i<3 ; i++)
    {
        for(j=0; j<4 ; j++)
        {
           scanf("%d",&m[i][j]);
        }

    }
    printf("\n        Sua matriz:\n\n");
    for(i=0; i<3 ; i++)
    {
        printf(" ");
        for(j=0; j<4 ; j++)
        {
           printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
