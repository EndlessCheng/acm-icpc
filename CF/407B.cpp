#include<bits/stdc++.h>
using namespace std;
const int mx = 1005;
const int mod = 1000000007;

long long dp[mx], a[mx];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp[0] = -1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
		dp[i] = (dp[i - 1] + 1 + dp[i - 1] - dp[a[i] - 1] + 1) % mod; // 前缀和
	cout << (dp[n] + 1 + mod) % mod;
	return 0;
}
