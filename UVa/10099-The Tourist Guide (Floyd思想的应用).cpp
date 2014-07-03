#include <cstdio>
#include <cstring>
#define N 110
int d[N][N];
int n,m,s,t,num;

int min(int a ,int b)
{ return a<b?a:b; }
int max(int a, int b)
{ return a>b?a:b; }
void DP()
{
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
             for(int j=1; j<=n; j++)
                 d[i][j]=max(d[i][j] , min(d[i][k],d[k][j]));
}
int main()
{
    int T=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(!n && !m)  break;
        memset(d,0,sizeof(d));
        for(int i=1; i<=m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            d[u][v]=d[v][u]=w;
        }
        scanf("%d%d%d",&s,&t,&num);
        DP();
        T++;
        printf("Scenario #%d\n",T);
        d[s][t]--;  //导游占了一个位置，实际上每次送过去的游客人数要少一位
        if((num%d[s][t]) == 0)
            printf("Minimum Number of Trips = %d\n",num/d[s][t]);
        else
            printf("Minimum Number of Trips = %d\n",(num/d[s][t])+1);
        printf("\n");

    }
    return 0;
}
