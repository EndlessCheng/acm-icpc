#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

const int N = 20005;
const int d[5][2] = {{ -1, 1}, {0, 2}, {1, 1}, {1, -1}, {0, -2}};

struct Point
{
	int x, y;
	Point() {}
	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
} p[N];

int a, b;

void init()
{
	int pn = 1, x = 0, y = 0;
	p[pn++] = Point(x, y);
	y -= 2;
	p[pn++] = Point(x, y);
	for (int i = 1; i <= 60; i++)
	{
		int j, k;
		for (j = 0; j < 5; j++)
		{
			for (k = 0; k < i; k++)
			{
				x += d[j][0];
				y += d[j][1];
				p[pn++] = Point(x, y);
			}
		}
		y -= 2;
		p[pn++] = Point(x, y);
		for (j = 0; j < i; j++)
		{
			x--;
			y--;
			p[pn++] = Point(x, y);
		}
	}
}

int main()
{
	init();
	while (~scanf("%d%d", &a, &b) && a || b)
	{
		int x = abs(p[a].x - p[b].x);
		int y = abs(p[a].y - p[b].y);
		printf("The distance between cells %d and %d is ", a, b);
		if (y <= x) printf("%d.\n", x);
		else
		{
			printf("%d.\n", x + (y - x) / 2);
		}
	}
	return 0;
}
