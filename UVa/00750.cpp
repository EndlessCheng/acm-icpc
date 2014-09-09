#include<bits/stdc++.h>
using namespace std;

int x = 1;
int xx , yy;

void check(int a[])
{
	bool flag = 1;
	for (int i = 0 ; i < 8 ; ++i)
	{
		for (int j = i + 1 ; j < 8 ; ++j)
		{
			if (j - i == abs(a[i] - a[j]) || a[yy - 1] != xx)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0) break;
	}
	if (flag == 1)
	{
		printf("%2d      %d %d %d %d %d %d %d %d\n" , x++ , a[0] , a[1] , a[2] , a[3] , a[4] , a[5] , a[6] , a[7]);
	}
}

int main()
{
	int t;
	cin >> t;
	for (int o = 0 ; o < t ; ++o)
	{
		x = 1;
		cin >> xx >> yy;
		int a[8] = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8};
		cout << "SOLN       COLUMN" << endl;
		cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
		while (next_permutation(a , a + 8))
		{
			check(a);
		}
		if (o != t - 1) cout << endl;
	}
	return 0;
}
