#include<iostream>
#include<cstdio>
using namespace std;

inline int cubo(int a)
{
	return a * a * a;
}

int main()
{
	int n, x, y;
	while (scanf("%d", &n))
	{
		if (n == 0) break;
		x = y = 0;
		while (1)
		{
			if (n == cubo(x) - cubo(y))
			{
				printf("%d %d\n", x, y);
				break;
			}
			if (n < cubo(x) - cubo(y)) y++;
			if (n > cubo(x) - cubo(y)) x++; /// 很好的操作。
			if (cubo(x) - cubo(y) == 0 || x >= 60 || y >= 59) /// 很好的观察
			{
				printf("No solution\n");
				break;
			}
		}
	}
	return 0;
}
