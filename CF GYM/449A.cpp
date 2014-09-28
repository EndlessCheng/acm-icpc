#include<cstdio>
#include<algorithm>
long long calc(int n, int m, int k)
{
	if (k < n) return 1LL * n / (k + 1) * m; // 横着或竖着k刀
	k -= n - 1;
	return 1LL * m / (k + 1); // 补刀
}
int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	if (k > n + m - 2) puts("-1");
	else printf("%I64d", std::max(calc(n, m, k), calc(m, n, k)));
}
