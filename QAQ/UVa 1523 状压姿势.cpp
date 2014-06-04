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
#define Uni(a) a.resize(unique(all(a)) - a.begin()) /// STL专用
#define SUni(a) sort(all(a)); Uni(a) /// STL专用
#define Cnt1(n) (__builtin_popcount(n))
#define Cntt1(n) (__builtin_popcountll(n)) /// 参数必须为ull类型
#define cb(n) (32 - __builtin_clz(n))
#define cbb(n) (64 - __builtin_clzll(n)) /// 参数必须为ull类型
#define sq(x) ((x) * (x))
#define Sqrt(n) (int)sqrt((double)(n) + 0.5)
#define mem(a, num) memset(a, num, sizeof(a))
#define cpy(to, from) memcpy(to, from, sizeof(from))
#define Rcpy(l, r, b) reverse_copy(l, r, b) /// 注意为左闭右开区间
 
typedef unsigned long long ull;
#define gr() greater<int>()
#define Acc(a, n) (accumulate(a, a + (n), 0))
#define uninum(a, n) (unique(a, a + (n)) - a) /// 试用前请sort
#define nth(a, k, n) nth_element(a + 0, a + k, a + n) /// *可能要事先--k
#define nthg(a, k, n) nth_element(a + 0, a + k, a + n, greater<int>()) /// *可能要事先--k
#define Min(a, n) (*min_element(a, a + (n)))
#define Max(a, n) (*max_element(a, a + (n)))
#define Minpos(a, n) (min_element(a, a + (n)) - a)
#define Maxpos(a, n) (max_element(a, a + (n)) - a)
#define Lowpos(a, n, x) (lower_bound(a, a + (n), x) - a)
#define Upppos(a, n, x) (upper_bound(a, a + (n), x) - a)
#define BS(a, n, x) binary_search(a, a + (n), x) /// 返回bool值
#define Range(a, n, x) equal_range(a, a + (n), x) /// 返回pair
#define Fpos(a, n, x) (find(a, a + (n), x) - a)
 
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
#define SL(a) scanf("%lld", &a)
#define SLL(a, b) scanf("%lld%lld", &a, &b)
#define SLLL(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
#define SLLLL(a, b, c, d) scanf("%lld%lld%lld%lld", &a, &b, &c, &d)
#define SD(a) scanf("%lf", &a)
#define SDD(a, b) scanf("%lf%lf", &a, &b)
#define SDDD(a, b, c) scanf("%lf%lf%lf", &a, &b, &c)
#define SA(a, i, n) For(i, n) scanf("%d", a + i) /// 便于扩展 *不要在后面加逗号！
#define SAA(a, i, n, j, m) For(i, n) For(j, m) SI(a[i][j]) /// *不要在后面加逗号！
#define GC(c) (c = getchar())
#define GCn() getchar()
#define SS(s) scanf("%s", s)
#define SSS(s, s2) scanf("%s%s", s, s2)
 
typedef multiset<int>::iterator msiter;
typedef multimap<int, int>::iterator mmter;
#define PI(a) printf("%d\n", a)
#define PII(a, b) printf("%d %d\n", a, b)
#define PIII(a, b, c) printf("%d %d %d\n", a, b, c)
#define PL(a) printf("%lld\n", a)
#define PLL(a, b) printf("%lld %lld\n", a, b)
#define PLLL(a, b, c) printf("%lld %lld %lld\n", a, b, c)
#define PD(a) printf("%f\n", a)
#define PDD(a, b) printf("%f %f\n", a, b)
#define PDDD(a, b, c) printf("%f %f %f\n", a, b, c)
#define PA(a, i, n) For(i, (n) - 1) printf("%d ", a[i]); PI(a[(n) - 1]) /// 由于要支持STL的数据类型，故不用+的形式，必要时请手动改成+
#define PAA(a, i, n, j, m) For(i, n) {For(j, (m) - 1) printf("%d ", a[i][j]); PI(a[i][(m) - 1]);}
#define PAn(a, i, n) For(i, n) PI(a[i])
#define PiA(a, i, n) For(i, n) PII(i, a[i]) /// debug用
#define rPA(a, i, n) rForr(i, n - 1, 1) printf("%d ", a[i]); PI(a[0])
#define rPAn(a, i, n) rFor(i, n - 1) PI(a[i])
#define PC(c) putchar(c)
#define PCn() putchar(10)
#define PCs() putchar(32)
 
#define Fin(f) freopen(f, "r", stdin) /// 请手动加.in
#define Fout(f) freopen(f, "w", stdout) /// 请手动加.out
#define random(m) ((rand() << 16 | rand()) % m) /// [0,m)之间的伪随机数
#define SR() srand((unsigned)time(NULL))
 
typedef long double ld;
const int inf = 0x3f3f3f3f; /// 1.06e9 (INT_MAX为2.147e9)
const long long llinf = 0x3f3f3f3f3f3f3f3f; /// 4.56e18
const double pi = acos(-1.0);
//const double tens[11] = {0.0, 1e-1, 1e-2, 1e-3, 1e-4, 1e-5, 1e-6, 1e-7, 1e-8, 1e-9, 1e-10};
//double fgcd(double a, double b) {return fabs(b) > eps ? fgcd(b, fmod(a, b)) : a;}
 
//const int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
//const int dirr[8][2] = {1, 0, 1, 1, 0, 1, -1, 1, -1, 0, -1, -1, 0, -1, 1, -1};
//const int knight_dir[8][2] = {1, 2, 1, -2, -1, 2, -1, -2, 2, 1, 2, -1, -2, 1, -2, -1};
/// 不可使用如下间接保留字：rank, tm,time, write, j0,j1,jn,y0,y1,yn
/// 如果用gets(s), GC(ch)读入WA的话，请用SS(s), scanf(" %c ", &ch)代替
/// 在main()中大量初始化STL类型容易死机
/// 注意strncpy不会加尾0，请手动添加
/// 相对位置不变的排序stable_sort(a, a + n);
/// C++会帮你往上类型转换，但G++不会
/*G++扩栈
int __size__ = 256 << 20; // 256MB
char *__p__ = (char*)malloc(__size__) + __size__;
__asm__(”movl %0, %%esp\n” :: ”r”(__p__));
*/
 
typedef pair<int, int> p2; /// 赋值时直接SII(a[i].x, a[i].y)就行, 有时候用ll
typedef pair<pair<int, int>, int> p3;
typedef pair<int, pair<int, int> > pi3;
//#define x first
//#define y second
//#define MT(a, b, c) make_pair(make_pair(a, b), c)
 
//const double eps = 1e-8;
//const int mod = int(1e9) + 7;
#define Pcas() printf("Case #%d: ", ++cas) /// 请仔细对照
const int mx = int(1e5) + 5;
const double INF = 1e20;
 
double ans;
int ans_arr[8], d[2][4];
double value[8];
bool check[4];
 
bool read()
{
 bool ok = false;
 for (int i = 0; i < 8; ++i)
 {
  scanf("%lf", &value[i]);
  if (value[i]) ok = true;
 }
 return ok;
}
 
void dfs(int cur)
{
 if (cur == 4)
 {
#define v(i) value[ans_arr[i]]
  ans = min(ans, hypot(v(0) + v(4) + v(1) - v(2) - v(7) - v(3), v(0) + v(5) + v(2) - v(1) - v(6) - v(3)));
  return;
 }
 for (int i(0); i < 4; ++i)
 {
  if (check[i]) continue;
  check[i] = true;
  ans_arr[cur + 4] = d[1][i];
  dfs(cur + 1);
  check[i] = false;
 }
}
 
double solve()
{
 ans = INF;
 for (int s = 0; s < (1 << 8); ++s)
 {
  if (Cnt1(s) != 4) continue;
  int ta(0), tb(0);
  for (int i(0); i < 8; ++i)
   if (s & (1 << i)) d[0][ta++] = i;
   else d[1][tb++] = i;
  for (int i(0); i < 4; ++i) ans_arr[i] = d[0][i];
  mem(check, 0);
  dfs(0);
  swap(ans_arr[2], ans_arr[3]);
  dfs(0);
  swap(ans_arr[1], ans_arr[3]);
  dfs(0);
 }
 return ans;
}
 
int main()
{
 while (read()) printf("%.3f\n", solve());
 return 0;
}
