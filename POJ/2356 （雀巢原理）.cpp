#include<cstdio>
#include<cstring>

int a[10001], pos[10001];

int main() {
	int n, i, sum = 0, l, r;
	scanf("%d", &n);
	memset(pos, -1, sizeof(pos));
	pos[0] = 0;
	for (i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		sum = (sum + a[i]) % n;
		if (pos[sum] == -1)
			pos[sum] = i;
		else {
			l = pos[sum] + 1;
			r = i;
			break;
		}
	}
	printf("%d\n", r - l + 1);
	for (i = l; i <= r; ++i)
		printf("%d\n", a[i]);
	return 0;
}
