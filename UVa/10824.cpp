#include<bits/stdc++.h>
using namespace std;
const int mx = int(2e3) + 5;
const double eps = 1e-8;
const double pi = acos(-1.0);
struct comp {bool operator()(const double a, const double b)const {return a + eps < b;}};
#define Lpos(a, n, x) (lower_bound(a, a + (n), x, comp()) - (a))

double angle[mx];
int n;
bool vis[mx];

int solve(int k)
{
	memset(vis, 0, sizeof(vis));
	int i, j, ans = 0, pos;
	double sum, d = 2 * pi / k;
	for (i = 0; i + k <= n; ++i)
	{
		if (vis[i]) continue;
		sum = angle[i];
		for (j = 1; j < k; ++j)
		{
			sum += d;  // 不推荐用 +=d，不过还好误差不是很大
			pos = Lpos(angle, n, sum);
			if (pos == n || fabs(sum - angle[pos]) > eps) break; // 未找到
			vis[pos] = true;
		}
		if (j == k) ++ans;
	}
	return ans;
}

int main()
{
	int i, k, ans, cas = 0;
	double x, y;
	while (scanf("%d", &n), n)
	{
		printf("Case %d:\n", ++cas);
		for (i = 0; i < n; ++i) scanf("%lf%lf", &x, &y), angle[i] = atan2(y, x);
		sort(angle, angle + n);
		for (k = 3; k <= n; ++k) if (ans = solve(k)) printf("%d %d\n", k, ans);
	}
	return 0;
}
