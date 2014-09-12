#include<stdio.h>
int main()
{	int i,j,n,t,a[26][200];
	for(i=1;i<=20;i++)
		a[i][0]=1;
	for(n=2;n<=20;n++)
		for(i=1;i<n;i++)
			for(j=0;j<=190;j++)
				if(a[i][j]==1)
					a[n][(n-i)*i+j]=1;		//(n-i)表示平行线的条数		i表示自由线的条数  j表示自由线的交点数
	while(~scanf("%d",&n))
	{	printf("0");
		t=n*(n-1)/2;
		for(i=1;i<=j;i++)
			if(a[n][i]==1)
				printf(" %d",i);
		printf("\n");
	}
	return 0;
}
