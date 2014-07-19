#include<bits/stdc++.h>
using namespace std;
#define For(i, n) for (i = 0; i < (n); ++i)
#define loop(it, a) for (it = a.begin(); it != a.end(); ++it)
typedef set<int>::iterator siter;
const char hint[11] = "RGBWY12345";
const int inf = 0x3f3f3f3f;

int id[128];
char s[5];
set<int> card, res;

int main()
{
	int i, j, n, ans;
	siter it;
	For(i, 10) id[hint[i]] = i;
	scanf("%d", &n);
	For(i, n) scanf("%s", s), card.insert(1 << id[s[0]] | 1 << id[s[1]]);
	ans = inf;
	n = card.size();
	For(i, 1 << 10)
	{
		res.clear();
		loop(it, card) res.insert(i & *it);
		if (res.size() == n) ans = min(ans, __builtin_popcount(i)); /// __builtin_popcount 统计 i 的二进制有多少个 1，但仅限于 G++
	}
	printf("%d\n", ans);
	return 0;
}
