#include<bits/stdc++.h>
using namespace std;
#define For(i, start, n) for (i = start; i < (n); ++i)
#define Forr(i, start, n, step) for (i = start; i < (n); i += step)
#define PB push_back
const int mx = int(1e5) + 5;

vector<int> multi, ans;
bool vis[mx];

int main() /*  思路和素数筛法是类似的  */
{       
	int n, m, i, j;
	scanf("%d", &n), m = n >> 1;
	For(i, 3, m + 1)
	{
		multi.clear();
		Forr(j, i, n + 1, i) if (!vis[j]) multi.PB(j); // 生成 p,2p,3p,4p,... 这些奇素数的倍数
		if (multi.size() & 1)
		{
			if (multi.size() == 1) continue;
			ans.PB(multi[0]), ans. PB(multi[2]), vis[multi[0]] = vis[multi[2]] = true; // 如果总共有奇数个，2p先不统计
			For(j, 3, multi.size()) ans.PB(multi[j]), vis[multi[j]] = true;
		}
		else For(j, 0, multi.size()) ans.PB(multi[j]), vis[multi[j]] = true;
	}
	Forr(i, 2, n + 1, 2) if (!vis[i]) ans.PB(i); // 剩余的偶数
	printf("%d\n", ans.size() >> 1);
	Forr(i, 1, ans.size(), 2) printf("%d %d\n", ans[i - 1], ans[i]);
}
