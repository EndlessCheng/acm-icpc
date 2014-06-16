
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
#define Unii(a, n) (unique(a, a + (n)) - a) /// 使用前请sort
#define Acc(a, n) (accumulate(a, a + (n), 0))
#define AaddB(a, n, b) transform(a, a + (n), b, a, plus<int>()) /// *慢的话就改为For(i, n) a[i] += b[i](注意加int i)
#define Cnt1(n) (__builtin_popcount(n))
#define Cntt1(n) (__builtin_popcountll(n)) /// 参数必须为ull类型
#define cb(n) (32 - __builtin_clz(n))
#define cbb(n) (64 - __builtin_clzll(n)) /// 参数必须为ull类型
#define sq(x) ((x) * (x))
#define Sqrt(n) (int)sqrt(0.5 + n)
#define mem(a, num) memset(a, num, sizeof(a))
#define cpy(to, from) memcpy(to, from, sizeof(from))
#define Rcpy(l, r, b) reverse_copy(l, r, b) /// 注意为左闭右开区间

typedef unsigned long long ull;
#define gr() greater<int>()
#define nth(a, k, n) nth_element(a + 0, a + k, a + n) /// *可能要事先--k
#define nthg(a, k, n) nth_element(a + 0, a + k, a + n, greater<int>()) /// *可能要事先--k
#define Min(a, n) (*min_element(a, a + (n)))
#define Max(a, n) (*max_element(a, a + (n)))
#define Minpos(a, n) (min_element(a, a + (n)) - (a))
#define Maxpos(a, n) (max_element(a, a + (n)) - (a))
#define Lowpos(a, n, x) (lower_bound(a, a + (n), x) - (a))
#define Upppos(a, n, x) (upper_bound(a, a + (n), x) - (a))
#define BS(a, n, x) binary_search(a, a + (n), x) /// 返回bool值
#define Range(a, n, x) equal_range(a, a + (n), x) /// 返回pair
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
#define SL(a) scanf("%lld", &a)
#define SLL(a, b) scanf("%lld%lld", &a, &b)
#define SLLL(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
#define SLLLL(a, b, c, d) scanf("%lld%lld%lld%lld", &a, &b, &c, &d)
#define SD(a) scanf("%lf", &a)
#define SDD(a, b) scanf("%lf%lf", &a, &b)
#define SDDD(a, b, c) scanf("%lf%lf%lf", &a, &b, &c)
#define SDDDD(a, b, c, d) scanf("%lf%lf%lf%lf", &a, &b, &c, &d)
#define SA(a, i, n) For(i, n) scanf("%d", a + i) /// 便于扩展 *不要在后面加逗号！
#define SAA(a, i, n, j, m) For(i, n) For(j, m) SI(a[i][j]) /// *不要在后面加逗号！
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
#define PL(a) printf("%lld\n", a)
#define PLL(a, b) printf("%lld %lld\n", a, b)
#define PLLL(a, b, c) printf("%lld %lld %lld\n", a, b, c)
#define PD(a) printf("%.10f\n", a)
#define PDD(a, b) printf("%f %f\n", a, b)
#define PDDD(a, b, c) printf("%f %f %f\n", a, b, c)
#define PA(a, i, n) For(i, (n) - 1) printf("%d ", a[i]); PI(a[(n) - 1]) /// *(有时要在前面加花括号)由于要支持STL的数据类型，故不用+的形式，必要时请手动改成+
#define PAA(a, i, n, j, m) For(i, n) {For(j, (m) - 1) printf("%d ", a[i][j]); PI(a[i][(m) - 1]);}
#define PAn(a, i, n) For(i, n) PI(a[i])
#define PiA(a, i, n) For(i, n) PII(i, a[i]) /// debug用
#define rPA(a, i, n) rForr(i, n - 1, 1) printf("%d ", a[i]); PI(a[0]) /// *(有时要在前面加花括号)
#define rPAn(a, i, n) rFor(i, n - 1) PI(a[i])
#define PC(c) putchar(c)
#define Pn() putchar(10)
#define Ps() putchar(32)

#define Fin(f) freopen(f, "r", stdin) /// 请手动加.in
#define Fout(f) freopen(f, "w", stdout) /// 请手动加.out
#define random(m) ((rand() << 16 | rand()) % m) /// [0,m)之间的伪随机数
#define SR() srand((unsigned)time(NULL))

typedef long double ld;
const int inf = 0x3f3f3f3f; /// 1.06e9 (INT_MAX为2.147e9)
const long long llinf = 0x3f3f3f3f3f3f3f3fLL; /// 4.56e18 (LLONG_MAX为9.22e18)
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
__asm__("movl %0, %%esp\n" :: "r"(__p__));
*/
//ios_base::sync_with_stdio(0);






const double eps = 1e-8;
const int mx = 205;

struct Point
{
	double x, y;
	Point(double x = 0, double y = 0): x(x), y(y) {}
	void read() {SDD(x, y);}
	bool operator < (const Point &b) const
    {
        return x < b.x || x == b.x && y < b.y;
        //return x + eps < b.x || fabs(x - b.x) < eps && y + eps < b.y;
    }
} p[mx], ans[mx];
typedef pair<double, pair<Point, Point> > p3;
#define MT(a, b, c) make_pair(a, make_pair(b, c))
typedef Point Vec;

Vec operator + (const Vec &a, const Vec &b) {return Vec(a.x + b.x, a.y + b.y);}
Vec operator - (const Point &a, const Point &b) {return Vec(a.x - b.x, a.y - b.y);}
Vec operator - (const Point &a) {return Vec(-a.x, -a.y);}
Vec operator * (const Vec &a, double p) {return Vec(a.x * p, a.y * p);}
Vec operator / (const Vec &a, double p) {return Vec(a.x / p, a.y / p);}

inline double Dot(const Vec &a, const Vec &b) {return a.x * b.x + a.y * b.y;}
inline double Cross(const Vec &a, const Vec &b) {return a.x * b.y - a.y * b.x;} /// b在a左边为正，b在a右边为负
inline double Len(const Vec &a) {return hypot(a.x, a.y);}
inline double Angle(const Vec &a, const Vec &b) {return acos(Dot(a, b) / Len(a) / Len(b));} /// 向量夹角
inline double cosA(const Vec &a, const Vec &b) {return Dot(a, b) / Len(a) / Len(b);} /// 向量夹角的余弦
inline Vec Rotate(const Vec &a, double rad) {return Vec(a.x * cos(rad) - a.y * sin(rad), a.x * sin(rad) + a.y * cos(rad));} /// 逆时针旋转向量a
inline Vec UnitVec(Vec &a) {double l = Len(a); return Vec(-a.y / l, a.x / l);} /// 返回a的单位法向量

/// 角度转弧度 *注意正负
inline double deg2rad(double deg) {return deg / 180.0 * pi;}
/// 弧度转角度 *注意正负
inline double rad2deg(double rad) {return rad / pi * 180.0;}
/// 求向量极角 *注意范围是(-pi,pi]
inline double PolarAngle(Vec v) {return atan2(v.y, v.x);}

struct Line
{
	Point p;
	Vec v;
	Line() {}
	Line(Point p, Vec v): p(p), v(v) {}
	Point point(double t) {return p + v * t;}
	/// d>0左平移, d<0右平移
	Line move(double d) {return Line(p + UnitVec(v) * d, v);}
};

struct CC
{
	Point c; /// *o
	double r;
	CC() {}
	CC(Point c, double r): c(c), r(r) {}
	Point point(double a) {return Point(c.x + r * cos(a), c.y + r * sin(a));}
} ci;

/// 直线与圆的交点ans
void getLineCCIntersection(Point &p, Point &p2, CC &C, vector<p3> &crossp)
{
	Line L(p, p2 - p);
	double a = L.v.x, b = L.p.x - C.c.x, c = L.v.y, d = L.p.y - C.c.y;
	double e = a * a + c * c, f = 2 * (a * b + c * d), g = b * b + d * d - C.r * C.r;
	double delta = f * f - 4 * e * g;
	/// 相交
	delta = sqrt(delta);
	double t1 = (-f - delta) / (2 * e);
	crossp.push_back(MT(PolarAngle(L.point(t1)), p, p2));
	double t2 = (-f + delta) / (2 * e);
	crossp.push_back(MT(PolarAngle(L.point(t2)), p, p2));
}

double maxA;

/// 求圆上一点与圆内两点的夹角的最大值, 三分的范围为(l, r), 注意角度值的连续性
double maxAngle(CC &ci, Point &p1, Point &p2, double l, double r)
{
	double tmp, m1, m2;
	double a1, a2;
	int i;
	Point cp1, cp2;
	For(i, 200) /// ?
	{
		tmp = (r - l) / 3;
		m1 = l + tmp;
		m2 = r - tmp;
		cp1 = ci.point(m1), cp2 = ci.point(m2);
		a1 = Angle(p1 - cp1, p2 - cp1);
		a2 = Angle(p1 - cp2, p2 - cp2);
		maxA = max(maxA, max(a1, a2));
		a1 + eps < a2 ? l = m1 : r = m2; /// 求极大值
	}
	l = Angle(p1 - cp1, p2 - cp1);
	//if(l<-eps) l+=2*pi;
	//if (l + eps > 2 * pi) l -= 2 * pi;
	//PD(l);
	return l;
}

vector<p3> crossp;
bool cmp(p3 a, p3 b)
{
	return a.first < b.first;
}

int convex_hull(Point *p, int n)
{
	sort(p, p + n);
//unique(p, p + n); /// *去重，看题意
	int cnt = 0, i;
	For(i, n) ///构建一个下凸包，从0到n-1
	{
		while (cnt >= 2 && Cross(ans[cnt - 1] - ans[cnt - 2], p[i] - ans[cnt - 2]) < eps)
			--cnt;
		ans[cnt++] = p[i];
	}
///注意在构建上凸包的过程中我们用到了n-1这个点
///为什么0要算两次？因为我们要借助它来删去那些在凸包内的点
	int tmp = cnt;
	rFor(i, n - 2) ///构建一个上凸包，从n-2到0
	{
		while (cnt > tmp && Cross(ans[cnt - 1] - ans[cnt - 2], p[i] - ans[cnt - 2]) < eps)
			--cnt;
		ans[cnt++] = p[i];
	}
	--cnt; ///0算了两次
	ans[cnt] = ans[0]; /// *方便后续操作
	return cnt;
}

int main()
{
//Fin("in.txt");
	int n, r, i;
	while (~SII(n, r))
	{
		ci = CC(Point(0, 0), r); /// 根据这个优化一下
		For(i, n) p[i].read();
		n = convex_hull(p, n);
		//p[n] = p[0];
		crossp.clear();
		For(i, n) getLineCCIntersection(ans[i], ans[i + 1], ci, crossp);
		//SUni(crossp);
		sort(all(crossp), cmp);
#define x first
#define y second
		crossp.PB(MP(crossp[0].x + 2 * pi, crossp[0].y));
		maxA = 0.0;
		For(i, crossp.size() - 1)
		{
			// maxA = max(maxA, maxAngle(ci, crossp[i].y.x, crossp[i + 1].y.x, 1e-2, 2*pi+1e-2));
			maxA = max(maxA, maxAngle(ci, crossp[i].y.x, crossp[i + 1].y.x, crossp[i].x - 1e-2, crossp[i + 1].x + 1e-2)); /// 4个优化成2个？
			maxA = max(maxA, maxAngle(ci, crossp[i].y.x, crossp[i + 1].y.y, crossp[i].x - 1e-2, crossp[i + 1].x + 1e-2));
			maxA = max(maxA, maxAngle(ci, crossp[i].y.y, crossp[i + 1].y.x, crossp[i].x - 1e-2, crossp[i + 1].x + 1e-2));
			maxA = max(maxA, maxAngle(ci, crossp[i].y.y, crossp[i + 1].y.y, crossp[i].x - 1e-2, crossp[i + 1].x + 1e-2));
		}
		PD(maxA);
	}
	return 0;
}
