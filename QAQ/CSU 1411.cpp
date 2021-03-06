#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <bitset>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#define dou double
#define mem(a) memset(a, 0, sizeof(a))
#define memm(a) memset(a, -1, sizeof(a))
#define LL long long
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
#define FI first
#define SE second
#define RI(a) scanf("%d", &(a))
#define RII(a, b) scanf("%d%d", &(a), &(b))
#define RIII(a, b, c) scanf("%d%d%d", &(a), &(b), &(c))
#define RL(a) scanf("%I64d", &(a))
#define RLL(a, b) scanf("%I64d%I64d", &(a), &(b))
#define RLLL(a, b, c) scanf("%I64d%I64d%I64d", &(a), &(b), &(c))
#define PI(r) printf("%d\n", (r))
#define PL(r) printf("%I64d\n", (r))
#define RS(s) scanf("%s", (s))
#define SL(a) strlen(a)
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define FOR(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
//Segment tree
#define MID ((l + r) >> 1)
#define L (one_can_have << 1)
#define R ((one_can_have << 1) | 1)
#define LC L, l, MID
#define RC R, MID + 1, r
#define LB(one_can_have) ((one_can_have) & (-(one_can_have)))
#pragma warning (disable : 4996)
//#pragma comment(linker, "/STACK:102400000,102400000")
#define EPS 1e-8
#define INF 2000000000
#define LIM (1ll << 60)
#define MOD 1000000007
#define N 111111
using namespace std;

char s[N];
int n, len, tot;
int one_pos[N], sumpos_1_r[N];

bool good(int one_can_have)
{
	int mid = (one_can_have + 1) >> 1, ans;
	if (one_can_have & 1)
	{
		REPP(i, 1, tot - one_can_have + 1)
		{
			ans = (sumpos_1_r[i + one_can_have - 1] - sumpos_1_r[i + mid - 1])
				  - (sumpos_1_r[i + mid - 2] - sumpos_1_r[i - 1]);
			if (ans - mid * (mid - 1) <= n) return true;
		}
	}
	else
	{
		REPP(i, 1, tot - one_can_have + 1)
		{
			ans = (sumpos_1_r[i + one_can_have - 1] - sumpos_1_r[i + mid - 1])
				  - (sumpos_1_r[i + mid - 1] - sumpos_1_r[i - 1]);
			if (ans - mid * mid <= n) return true;
		}
	}
	return false;
}

int main()
{
	int t, one_can_have, y, z, ca = 1;
	RI(t);
	while (t--)
	{
		RS(s);
		RI(n);
		len = SL(s), tot = 0;
		REP(i, len) if (s[i] == '1') one_pos[++tot] = i;
		REPP(i, 1, tot) sumpos_1_r[i] = sumpos_1_r[i - 1] + one_pos[i];
		REPP(i, 1, tot) PI(sumpos_1_r[i]);
		if (tot == 0)
		{
			PI(0);
			continue;
		}
		int l = -1, r = tot + 1;
		while (l + 1 < r)
		{
			int mid = (l + r) >> 1;
			good(mid) ? l = mid : r = mid;
		}
		PI(l);
	}
	return 0;
}
