#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
char mp[15][15];
int n,m,k;
int v[15][15];
int go[4][2]={{0,1},{1,0},{-1,0},{0,-1}};

int dfs(int x,int y,int j)
{
	if(mp[x][y]=='o')
		j++;
	if(j==0)
		return 1;
	v[x][y]=1;
	for(int i=0;i<4;i++)
		if(mp[(x+go[i][0]+n)%n][(y+go[i][1]+m)%m]!='#'&&!v[(x+go[i][0]+n)%n][(y+go[i][1]+m)%m])
			if(dfs((x+go[i][0]+n)%n,(y+go[i][1]+m)%m,j-1)==1)
				return 1;
	v[x][y]=0;			
	return 0;
}

int main()
{
	int T,q=0;
	cin>>T;
	while(T--)
	{
		memset(v,0,sizeof(v));
		q++;
		cout<<"Case #"<<q<<": ";
		cin>>n>>m>>k;
		for(int i=0;i<n;i++)
			scanf("%s",mp[i]);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(mp[i][j]=='x')
				{
					if(dfs(i,j,k-1))
						cout<<"Fits perfectly!\n";
					else
						cout<<"Oh no, snake's too fat!\n";
				}
	}
}
