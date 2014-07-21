#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 100005;
int t, n, m, node[N];
vector<int> g[N];

int cal(int u) {
	int ans = 0;
	for (int i = 0; i < g[u].size(); i++)
		ans += node[g[u][i]];
	return ans;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		int u, v;
		for (int i = 1; i <= n; i++) {
			g[i].clear();
			node[i] = 0;
		}
		while (m--) {
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int q;
		scanf("%d", &q);
		while (q--) {
			int c, a, b;
			scanf("%d", &c);
			if (c == 0) {
				scanf("%d%d", &a, &b);
				node[a] += b;
			}
			else {
				scanf("%d", &a);
				printf("%d\n", cal(a));
			}
		}
	}
	return 0;
}
