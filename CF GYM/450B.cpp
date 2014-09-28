#include<cstdio>
int main()
{
	int x, y, n, m = int(1e9) + 7;
	scanf("%d%d%d", &x, &y, &n);
	int ans[6] = { -y + x, x, y, y - x, -x, -y}; // 6可要可不要
	printf("%d", (ans[n % 6] % m + m) % m);
}
