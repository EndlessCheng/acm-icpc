#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std; 
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
#define swap(a, b) int t = a; a = b; b = t;
#define maxn 110
// q队列，vis访问标志，erg能量，cnt循环计数，sout dfs的访问标志，
int g[maxn][maxn], dis[maxn], q[maxn], vis[maxn], erg[maxn], cnt[maxn], n, m, tmp, sout[maxn];

void dfs(int a)
{
    sout[a] = 1;
    for (int i = 1; i <= n; i++)
    {
        if(g[a][i] && !sout[i]) dfs(i);
    }
}

void Spfa()
{
	int front = 0, rear = 0, ok = false;
	memset(dis, 0, sizeof(dis));
	memset(vis, false, sizeof(vis));
	memset(cnt, false, sizeof(cnt));
	dis[1] = 100;
	vis[1] = true;
	rear++;
	q[rear] = 1;
	while(front != rear) {
		front = (front + 1) % maxn;
		int t = q[front];
		repf(i, 1, n) {
			if(g[t][i] && dis[t] + erg[i] > dis[i]) { 
				dis[i] = dis[t] + erg[i];
				if(!vis[i]) {
					rear = (rear + 1) % maxn;
					q[rear] = i;
					vis[i] = true;
				}
			}
		}
		cnt[t]++;
		if(cnt[t] < maxn) vis[t] = false;
		else {
			memset(sout, 0, sizeof(sout)); 
			dfs(t);
			if(sout[n]) { ok = true; break; }
			}
		if(dis[n] > 0) { ok = true; break;}
	}
	if(ok) puts("winnable");
	else puts("hopeless");
 }
 
int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	while(scanf("%d", &n) != EOF)
	{
		if(n == -1) break;
		memset(g, 0, sizeof(g));
		memset(erg, 0, sizeof(erg));
		repf(i, 1, n) {
			scanf("%d%d", &erg[i], &m);
			rep(j, m) {
				scanf("%d", &tmp);
				g[i][tmp] = 1;
			}
		}
		Spfa();
	}
	return 0;
}
