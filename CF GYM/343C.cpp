/**
    从左到右挨个使用读头，然后贪心地挨个访问
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL H[100005], P[100005];

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%I64d", &H[i]);
	for (int i = 0; i < M; i++) scanf("%I64d", &P[i]);
	LL l = -1, r = 1LL << 40, m;
	while (l + 1 < r)
	{
		m = (r + l) >> 1;
		int k = 0;
		for (int i = 0; i < N; i++)
		{
			int j;
			for (j = k; j < M; j++)
			{
				LL d = min(abs(H[i] - P[k]), abs(H[i] - P[j])) + P[j] - P[k];
				if (d > m) break;
			}
			k = j;
		}
		k == M ? r = m : l = m;
	}
	printf("%I64d", r);
	return 0;
}
