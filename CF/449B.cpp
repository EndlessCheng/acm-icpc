#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define For(i, n) for (i = 0; i < (n); ++i)

typedef pair<bool, int> p2;
typedef pair<long long, p2> p3;
const int mx = int(1e5) + 5;

vector<p3> G[mx];
bool vis[mx];

void read(int m, int k)
{
	int i, from, to, cost;
	For(i, m)
	{
		scanf("%d%d%d", &from, &to, &cost);
		G[from].PB(p3(cost, p2(false, to)));
		G[to].PB(p3(cost, p2(false, from)));
	}
	For(i, k)
	{
		scanf("%d%d", &to, &cost);
		G[1].PB(p3(cost, p2(true, to)));
	}
}

int dj(int st)
{
	priority_queue<p3, vector<p3>, greater<p3> > pq; /// (disTov, isTrainRoute, v)
	p3 p, e;
	int v, i, cnt = 0;
	pq.push(p3(0, p2(false, st)));
	while (!pq.empty())
	{
		p = pq.top(), pq.pop();
#define dis first
#define isTrainRoute second.first
#define now second.second
		if (vis[v = p.now])
		{
			if (p.isTrainRoute) ++cnt;
			continue;
		}
		For(i, G[v].size())
		{
			e = G[v][i];
#define cost first
#define to second
			pq.push(p3(p.dis + e.cost, e.to));
		}
		vis[v] = true;
	}
	return cnt;
}

int main()
{
	int m, k;
	scanf("%*d%d%d", &m, &k);
	read(m, k);
	printf("%d", dj(1));
	return 0;
}
