#include<cstdio>
const int maxn = 1005;
const int MOD = 10056;
int C[maxn][maxn], f[maxn];

/// 递推组合数
void init()
{
	for (int i = 0; i <= maxn; i++)
	{
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
	}
}

int main()
{
	init();
	f[0] = 1;
	for (int i = 1; i <= maxn; i++)
	{
		f[i] = 0;
		for (int j = 1; j <= i; j++) f[i] = (f[i] + C[i][j] * f[i - j]) % MOD; /// 递推结果
	}
	int T, n;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d", &n);
		printf("Case %d: %d\n", cas, f[n]);
	}
	return 0;
}
