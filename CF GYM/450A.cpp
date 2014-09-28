#include<bits/stdc++.h>
using namespace std;
int t[105], n, m, a;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &a), t[i] = (a - 1) / m + 1;
	printf("%d", max_element(t, t + n, less_equal<int>()) - t + 1);
}
