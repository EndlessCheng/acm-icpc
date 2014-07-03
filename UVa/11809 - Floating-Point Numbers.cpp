#include<bits/stdc++.h>
using namespace std;

#define Inter(v, a, n, b, m) v.resize(set_intersection(a, a + (n), b, b + (m), v.begin()) - v.begin())
#define SInter(v, a, n, b, m) v.resize((n) + (m)); sort(a, a + (n)); sort(b, b + (m)); Inter(v, a, n, b, m)
#define Union(v, a, n, b, m) v.resize(set_union(a, a + (n), b, b + (m), v.begin()) - v.begin());
#define SUnion(v, a, n, b, m) v.resize((n) + (m)); sort(a, a + (n)); sort(b, b + (m)); Union(v, a, n, b, m)
#define Diff(v, a, n, b, m) v.resize(set_difference(a, a + (n), b, b + (m), v.begin()) - v.begin())
#define SDiff(v, a, n, b, m) v.resize((n) + (m)); sort(a, a + (n)); sort(b, b + (m)); Diff(v, a, n, b, m)
#define Sym(v, a, n, b, m) v.resize(set_symmetric_difference(a, a + (n), b, b + (m) v.begin()) - v.begin())
#define SSym(v, a, n, b, m) v.resize((n) + (m)); sort(a, a + (n)); sort(b, b + (m)); Sym(v, a, n, b, m)

typedef long long ll;
#define PB push_back
#define MP make_pair
#define all(a) a.begin(), a.end()
#define Uni(a) a.resize(unique(all(a)) - a.begin()) /// STLר��
#define SUni(a) sort(all(a)); Uni(a) /// STLר��
#define Unii(a, n) (unique(a, a + (n)) - a) /// ʹ��ǰ��sort
#define Acc(a, n) (accumulate(a, a + (n), 0)) /// ע��0LL!!!!!�Լ�0.0!!!
#define AaddB(a, n, b) transform(a, a + (n), b, a, plus<int>()) /// *���Ļ��͸�ΪFor(i, n) a[i] += b[i](ע����int i)
#define Cnt1(n) (__builtin_popcount(n))
#define Cntt1(n) (__builtin_popcountll(n)) /// ��������Ϊull����
#define cb(n) (32 - __builtin_clz(n))
#define cbb(n) (64 - __builtin_clzll(n)) /// ��������Ϊull����
#define sq(x) ((x) * (x))
#define Sqrt(n) (int)sqrt(0.5 + n)
#define mem(a, num) memset(a, num, sizeof(a))
#define cpy(to, from) memcpy(to, from, sizeof(from))
#define Rcpy(l, r, b) reverse_copy(l, r, b) /// ע��Ϊ�����ҿ�����

typedef unsigned long long ull;
#define gr() greater<int>()
#define nth(a, k, n) nth_element(a + 0, a + k, a + n) /// *����Ҫ����--k
#define nthg(a, k, n) nth_element(a + 0, a + k, a + n, greater<int>()) /// *����Ҫ����--k
#define Min(a, n) (*min_element(a, a + (n)))
#define Max(a, n) (*max_element(a, a + (n)))
#define Minpos(a, n) (min_element(a, a + (n)) - (a))
#define Maxpos(a, n) (max_element(a, a + (n)) - (a))
#define Lowpos(a, n, x) (lower_bound(a, a + (n), x) - (a))
#define Upppos(a, n, x) (upper_bound(a, a + (n), x) - (a))
#define BS(a, n, x) binary_search(a, a + (n), x) /// ����boolֵ
#define Range(a, n, x) equal_range(a, a + (n), x) /// ����pair
#define Fpos(a, n, x) (find(a, a + (n), x) - (a))

typedef vector<int>::iterator viter;
#define For(i, n) for (i = 0; i < (n); ++i)
#define Forr(i, start, n) for (i = start; i < (n); ++i)
#define Forrr(i, start, n, step) for (i = start; i < (n); i += (step))
#define rFor(i, n) for (i = (n); i >= 0; --i)
#define rForr(i, n, end) for (i = n; i >= (end); --i)
#define rForrr(i, n, end, step) for (i = n; i >= (end); i -= (step))
#define loop(a) for (it = a.begin(); it != a.end(); ++it)

typedef set<int>::iterator siter;
typedef map<int, int>::iterator miter;
#define SI(a) scanf("%d", &a)
#define SII(a, b) scanf("%d%d", &a, &b)
#define SIII(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define SIIII(a, b, c, d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define SIIIII(a, b, c, d, e) scanf("%d%d%d%d%d", &a, &b, &c, &d, &e)
#define SIIIIII(a, b, c, d, e, f) scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f)
#define SL(a) scanf("%lld", &a)
#define SLL(a, b) scanf("%lld%lld", &a, &b)
#define SLLL(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
#define SLLLL(a, b, c, d) scanf("%lld%lld%lld%lld", &a, &b, &c, &d)
#define SD(a) scanf("%lf", &a)
#define SDD(a, b) scanf("%lf%lf", &a, &b)
#define SDDD(a, b, c) scanf("%lf%lf%lf", &a, &b, &c)
#define SDDDD(a, b, c, d) scanf("%lf%lf%lf%lf", &a, &b, &c, &d)
#define SA(a, i, n) For(i, n) scanf("%d", a + i) /// ������չ *��Ҫ�ں����Ӷ��ţ�
#define SAA(a, i, n, j, m) For(i, n) For(j, m) SI(a[i][j]) /// *��Ҫ�ں����Ӷ��ţ�
#define GC(c) (c = getchar())
#define GCn() getchar()
#define UC(c) ungetc(c, stdin)
#define SS(s) scanf("%s", s)
#define SSS(s, s2) scanf("%s%s", s, s2)

typedef multiset<int>::iterator msiter;
typedef multimap<int, int>::iterator mmter;
#define PI(a) printf("%d\n", a)
#define PII(a, b) printf("%d %d\n", a, b)
#define PIII(a, b, c) printf("%d %d %d\n", a, b, c)
#define PIIII(a, b, c, d) printf("%d %d %d %d\n", a, b, c, d)
#define PL(a) printf("%lld\n", a)
#define PLL(a, b) printf("%lld %lld\n", a, b)
#define PLLL(a, b, c) printf("%lld %lld %lld\n", a, b, c)
#define PD(a) printf("%f\n", a)
#define PDD(a, b) printf("%f %f\n", a, b)
#define PDDD(a, b, c) printf("%f %f %f\n", a, b, c)
#define PA(a, i, n) For(i, (n) - 1) printf("%d ", a[i]); PI(a[(n) - 1]) /// *(��ʱҪ��ǰ���ӻ�����)����Ҫ֧��STL���������ͣ��ʲ���+����ʽ����Ҫʱ���ֶ��ĳ�+
#define PAA(a, i, n, j, m) For(i, n) {For(j, (m) - 1) printf("%d ", a[i][j]); PI(a[i][(m) - 1]);}
#define PAn(a, i, n) For(i, n) PI(a[i])
#define PiA(a, i, n) For(i, n) PII(i, a[i]) /// debug��
#define rPA(a, i, n) rForr(i, n - 1, 1) printf("%d ", a[i]); PI(a[0]) /// *(��ʱҪ��ǰ���ӻ�����)
#define rPAn(a, i, n) rFor(i, n - 1) PI(a[i])
#define PC(c) putchar(c)
#define Pn() putchar(10)
#define Ps() putchar(32)

#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)
#define Fin(f) freopen(f, "r", stdin) /// ���ֶ���.in
#define Fout(f) freopen(f, "w", stdout) /// ���ֶ���.out
#define random(m) ((rand() << 16 | rand()) % m) /// [0,m)֮����α������
#define SR() srand((unsigned)time(NULL))

typedef long double ld;
const int inf = 0x3f3f3f3f; /// 1.06e9 (INT_MAXΪ2.147e9)
const long long llinf = 0x3f3f3f3f3f3f3f3fLL; /// 4.56e18 (LLONG_MAXΪ9.22e18)
const double pi = acos(-1.0);
//const double tens[11] = {0.0, 1e-1, 1e-2, 1e-3, 1e-4, 1e-5, 1e-6, 1e-7, 1e-8, 1e-9, 1e-10};
//double fgcd(double a, double b) {return fabs(b) > eps ? fgcd(b, fmod(a, b)) : a;}

//const int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
//const int dirr[8][2] = {1, 0, 1, 1, 0, 1, -1, 1, -1, 0, -1, -1, 0, -1, 1, -1};
//const int knight_dir[8][2] = {1, 2, 1, -2, -1, 2, -1, -2, 2, 1, 2, -1, -2, 1, -2, -1};

/*0.012s*/

const double eps = 1e-6;
const double LOG2_10 = log2(10.0);

char s[100];

int main()
{
	ull M, E, b;
	double a, A, tmp, diff;
	while (scanf("%s", s), strcmp(s, "0e0"))
	{
		*strchr(s, 'e') = 32;
		sscanf(s, "%lf%llu", &a, &b);
		A = log2(a) + b * LOG2_10;
		For(M, 10)
		{
			tmp = log2(1 - 1.0 / (1 << (M + 1)));
			E = (ull)round(log2(A - tmp + 1));
			if (fabs(A - ((1 << E) - 1) - tmp) < eps) break;
		}
		printf("%llu %llu\n", M, E);
	}
	return 0;
}
