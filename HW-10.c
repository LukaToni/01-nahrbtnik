#include <stdio.h>
#include <stdlib.h>

int maxValue(int a,int b)
{
    return (a > b) ? a : b ;
}

void Knapsack(int items,int maxWeight, int *weight,int *value)
{
        int i;
        int j;
        int w;

        /*2 dimensional table*/
        int **dp = malloc(sizeof(int*)*(items+1));

        for(i = 0; i < items + 1 ; i++)
            dp[i] = malloc(sizeof(int)*(items+1));

        for(j = 0 ; j <= maxWeight ; j++)
                dp[0][j] = 0;

        /* dp[j][0]  set on 0 */
        for(j = 0; j <= items ; j++)
                dp[j][0] = 0;

        for(j = 1; j < items + 1 ; j++)
        {
                for(w = 0 ; w < maxWeight + 1 ; w++)
                {
                        dp[j][w] = dp[j-1][w]; /* ne vzamemo */

                        if(w-weight[j] >= 0)
                                dp[j][w] = maxValue( dp[j][w] , dp[j-1][w - weight[j]] + value[j] );
                }
        }
        printf("%d\n", dp[items][maxWeight]);
}

int main()
{
    int maxWeight;
    scanf("%d",&maxWeight);
    if(maxWeight < 1 || 1000000000 < maxWeight)
        return 0; /*error*/

    int *weight = malloc(sizeof(int)*41);
    int *value = malloc(sizeof(int)*41);

    int items = 0;
  
    while(scanf("%d%d", &weight[items+1] , &value[items+1] ) == 2)
    {
        /* 1 < weight[items] < 1000000 */
        if(weight[items] < 1 || 1000000000 < weight[items])
            return 0; /*error*/
            
       /* 1 < value[items] < 1000000 */
        if(value[items] < 1 || 1000000000 < value[items])
            return 0; /*error*/
            
        /*add item*/
        items++;
    }
    
    Knapsack(items,maxWeight,weight,value);

    return 0;
}
