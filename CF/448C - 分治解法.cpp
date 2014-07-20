#include<bits/stdc++.h>
using namespace std;

int a[5005];

int solve(int l, int r, int h) /*  @Tideline 超级好理解的分治算法   */
{
	if (l > r) return 0;
	if (l == r) return 1;
	int minh = *min_element(a + l, a + r + 1);
	if (minh > h) return min(minh - h + solve(l, r, minh), r - l + 1);
	// now minh == h
	int cnt = 0, p = l;
	for (int i = l; i <= r; ++i) if (a[i] == minh) cnt += solve(p, i - 1, h), p = i + 1;
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
