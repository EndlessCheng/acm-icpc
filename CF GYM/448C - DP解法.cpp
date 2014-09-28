#include<bits/stdc++.h>
using namespace std;

int h[5001], dp[5001][5001];

inline int imin(int a, int b) {return ~a && a < b ? a : b;}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &h[i]);
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i) /// 前i个fences已经涂完了
		for (int j = 0; j < i; ++j) /// 有h[j]行是横着涂的
			if (~dp[i - 1][j])
			{
				dp[i][i] = imin(dp[i][i], dp[i - 1][j] + max(0, h[i] - h[j]));
				if (h[i] > h[j]) dp[i][j] = dp[i - 1][j] + 1; /// 说明此时需要竖着涂一次
			}
	int ans = -1;
	for (int i = 0; i <= n; ++i)
		if (~dp[n][i]) ans = imin(ans, dp[n][i]);
	printf("%d", ans);
}
