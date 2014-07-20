#include<bits/stdc++.h>
using namespace std;

int a[5005];

int solve(int l, int r, int h) /*  @Tideline 超级好理解的分治算法   */
{
	if (l > r) return 0;
	if (l == r) return 1;
	int m = *min_element(a + l, a + r + 1);
	if (m > h) return min(m - h + solve(l, r, m), r - l + 1);
	// now m == h
	int cnt = 0, p = l;
	for (int i = l; i <= r; ++i) if (a[i] == m) cnt += solve(p, i - 1, h), p = i + 1;
	cnt += solve(p, r, h);
	return cnt;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	printf("%d", solve(1, n, 0));
}
