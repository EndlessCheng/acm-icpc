#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mx = int(1e4) + 5;
const int mxm = int(1e5) + 5;

struct edge
{
	int from, to, cost;
	void read() {scanf("%d%d%d", &from, &to, &cost);}
	bool operator < (const edge &b) const
	{
		return cost < b.cost;
	}
} e[mxm];

int fa[mx], n, m;
int find(int x) {return ~fa[x] ? fa[x] = find(fa[x]) : x;}

int Kruskal()
{
	sort(e, e + m);
	memset(fa, -1, sizeof(fa));
	int sum = 0, cnt = 0;
	for (int i = 0; i < m; ++i)
	{
		int fau = find(e[i].from), fav = find(e[i].to);
		if (fau != fav) fa[fau] = fav, sum += e[i].cost, ++cnt;
	}
	return cnt == n - 1 ? sum : -1;
}

