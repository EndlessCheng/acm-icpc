#include<cstdio>

double f[100005];

void init()
{
	f[2] = 1;
	for (int i = 2; i < 100000; i += 2)
		f[i + 2] = f[i] * (i - 1) / i;
}

int main()
{
	init();
	int n, t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		printf("%.4f\n", 1 - f[n]);
	}
	return 0;
}
