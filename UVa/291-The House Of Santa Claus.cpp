#include<bits/stdc++.h>
using namespace std;

int edge[6][6];

void makeEdge()
{
	memset(edge, 0, sizeof(edge));
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			if (i != j)
				edge[i][j] = 1;
		}
	}
	edge[4][1] = edge[1][4] = 0;
	edge[4][2] = edge[2][4] = 0;
}

void dfs(int x, int k, string s)
{
	s += char(x + '0');
	if (k == 8)
	{
		cout << s << endl;
		return;
	}
	for (int y = 1; y <= 5; y++)
	{
		if (edge[x][y])
		{
			edge[x][y] = edge[y][x] = 0;
			dfs(y, k + 1, s);
			edge[x][y] = edge[y][x] = 1;
		}
	}
}

int main()
{ 
	makeEdge();
	dfs(1, 0, "");
	return 0;
}
