#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<cassert>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<vector>
#include<string>
#include<bitset>
#include<list>
#include<deque>
#include<stack>
#include<queue>
#include<set>
#include<map>
//#include<bits/stdc++.h>
using namespace std;
const int maxn = 1100;
const int maxm = 10000;
int n, q;
vector<int>g[10];
int c[10];
struct Point
{
	int x, y;
	int getValueTo(Point p)
	{
		return (p.x - x) * (p.x - x) + (p.y - y) * (p.y - y);
	}
} p[maxn];
struct EDGE
{
	int u, v, d;
	bool operator<(const EDGE& rhs) const
	{
		return d < rhs.d;
	}
} e[maxn*maxn];
int edge;
int pa[maxn];
void makeset(int n)
{
	for (int i = 0; i <= n; i++) pa[i] = i;
}
int findset(int x)
{
	if (x != pa[x]) pa[x] = findset(pa[x]);
	return pa[x];
}
bool unionset(int x, int y)
{
	x = findset(x);
	y = findset(y);
	if (x != y)
	{
		pa[x] = y;
		return true;
	}
	return false;
}
int kruskal()
{
	int ans = 0;
	for (int i = 0; i < edge; i++)
	{
		if (unionset(e[i].u, e[i].v))
		{
			ans += e[i].d;
		}
	}
	return ans;
}
int main()
{
	while (~scanf("%d%d", &n, &q))
	{
		for (int i = 0; i < q; i++)
		{
			int cnt;
			scanf("%d%d", &cnt, &c[i]);
			for (int j = 0; j < cnt; j++)
			{
				int tmp;
				scanf("%d", &tmp);
				g[i].push_back(tmp);
			}
		}
		for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].x, &p[i].y);
		edge = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				e[edge].u = i;
				e[edge].v = j;
				e[edge++].d = p[i].getValueTo(p[j]);
			}
		}
		sort(e, e + edge);
		makeset(n);
		int ans = kruskal();
		for (int s = 1; s < (1 << q); s++)
		{
			makeset(n);
			int cost = 0;
			for (int i = 0; i < q; i++)
			{
				if (s & (1 << i))
				{
					cost += c[i];
					for (int j = 1; j < g[i].size(); j++)
					{
						unionset(g[i][j - 1], g[i][j]);
					}
				}
			}
			ans = min(ans, cost + kruskal());
		}
		printf("%d\n", ans);
	}
	return 0;
}
