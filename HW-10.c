#include <stdio.h>
#include <stdlib.h>

int maxValue(int a,int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void Knapsack(int items,int maxWeight, int *weight,int *value)
{
        int i;
        int j;
        int w;

        /*2 dimenzionalna tabela*/
        int **dp = malloc(sizeof(int*)*(items+1));
        /*nastavimo drugo diminzionalao*/
        for(i = 0; i < items + 1 ; i++)
        {
            dp[i] = malloc(sizeof(int)*(items+1));
        }

        /* dp[i][w] represents maximum value that can be attained if the maximum weight is w and
           items are chosen from 1...i */
        /* dp[0][w] = 0 for all w because we have chosen 0 items */

        /* dp[0][j]  vse nastavimo na 0 */

        for(j = 0 ; j <= maxWeight ; j++)
        {
                dp[0][j] = 0;
        }

        /* dp[j][0]  vse nastavimo na 0 */
        for(j = 0; j <= items ; j++)
        {
                dp[j][0] = 0;
        }
/*
123456789
123456000 4096
12345678 64
1024 134217728
12345678 96
999 999999
*/


        for(j = 1; j < items + 1 ; j++)
        {
                for(w = 0 ; w < maxWeight + 1 ; w++)
                {


                         dp[j][w] = dp[j-1][w]; /* ne vzamemo */

                        if(w-weight[j] >= 0)
                        {
                                /* vzamemo */
                                dp[j][w] = maxValue( dp[j][w] , dp[j-1][w - weight[j]] + value[j] );
                        }

                }
        }
        printf("%d\n", dp[items][maxWeight]);
}

int main()
{
    //prostor za podatke
    int maxWeight;
    scanf("%d",&maxWeight);
    if(maxWeight < 1 || 1000000000 < maxWeight)
    {
        return 0; /*napacen podatek*/
    }

    int *weight = malloc(sizeof(int)*41);
    int *value = malloc(sizeof(int)*41);

    int items = 0;
    /*dokler sta 2 elementa v vrstice se items povecuje za ena*/
    while(scanf("%d%d",&weight[items+1],&value[items+1]) == 2)
    {
        /* 1 < weight[items] < 1000000 */
        if(weight[items] < 1 || 1000000000 < weight[items])
        {
            return 0; /*napacen podatek*/
        }
       /* 1 < value[items] < 1000000 */
        if(value[items] < 1 || 1000000000 < value[items])
        {
            return 0; /*napacen podatek*/
        }
        /*pristejemo en popoln podatek*/
        items++;
    }
//    int i;
//    for (i = 0 ; i < items ; i++)
//        printf("%d %d\n", weight[i],value[i] );

    //printf("ITEMS %d\n", items );

//    if(items == 0)
//    {
//        printf("0\n");
//    }
//
//
//    else if(items == 1)
//    {
//        if(weight[0] < maxWeight)
//        {
//            printf("%d\n", value[0]);
//        }
//        else
//        {
//            printf("0\n");
//        }
//    }

//    else
//    {
        //items++;
        Knapsack(items,maxWeight,weight,value);
//    }
    return 0;
}
