#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<cmath>  
#include<vector>  
  
using namespace std;  
#define FOR(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)  
#define DOR(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)  
  
#define oo 1e6  
#define eps 1e-9  
#define nMax 5000  
  
//{  
#define pb push_back  
#define dbg(x) cerr << __LINE__ << ": " << #x << " = " << x << endl  
  
#define F first  
#define S second  
  
#define bug puts("OOOOh.....");  
#define zero(x) (((x)>0?(x):-(x))<eps)  
  
#define LL long long  
#define DB double   
  
#define sf scanf  
#define pf printf  
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)  
  
double const pi = acos(-1.0);  
  
double inline sqr(double x) { return x*x; }  
  
int dcmp(double x){  
    if(fabs(x)<eps) return 0;  
    return x>0?1:-1;  
}  
//}  
  
// Describe of the 2_K Geomtry  
// First Part : Point and Line  
// Second Part Cicle  
// Third Part Polygan  
  
// First Part:  
// ****************************** Point and Line *******************************\\  
//{  
  
class point {  
public:  
    double x,y;  
    point (double x=0,double y=0):x(x),y(y) {}  
    void make(double _x,double _y) {x=_x;y=_y;}  
    void read() { scanf("%lf%lf",&x,&y); }  
    void out() { printf("%.2lf %.2lf\n",x,y);}  
    double len() { return sqrt(x*x+y*y); }  
    point friend operator - (point const& u,point const& v) {  
        return point(u.x-v.x,u.y-v.y);  
    }  
    point friend operator + (point const& u,point const& v) {  
        return point(u.x+v.x,u.y+v.y);  
    }  
    double friend operator * (point const& u,point const& v) {  
        return u.x*v.y-u.y*v.x;  
    }  
    double friend operator ^ (point const& u,point const& v) {  
        return u.x*v.x+u.y*v.y;  
    }  
    point friend operator * (point const& u,double const& k) {  
        return point(u.x*k,u.y*k);  
    }  
    point friend operator / (point const& u,double const& k) { return point(u.x/k,u.y/k); }  
    friend bool operator < (point const& u,point const& v){  
        if(dcmp(v.x-u.x)==0) return dcmp(u.y-v.y)<0;  
        return dcmp(u.x-v.x)<0;  
    }  
    friend bool operator != (point const& u,point const& v){  
        return dcmp(u.x-v.x) || dcmp(u.y-v.y);  
    }  
  
    point rotate(double s) {  
        return point(x*cos(s) + y*sin(s),\  
                    -x*sin(s) + y*cos(s));  
    }  
};  
typedef class line{  
public:  
    point a,b;  
    line() {}  
    line (point a,point b):a(a),b(b){}  
    void make(point u,point v) {a=u;b=v;}  
    void read() { a.read(),b.read(); }  
}segment;  
  
double det(point u,point v) {  
    return u.x*v.y - u.y*v.x;  
}  
double dot(point u,point v) {  
    return u.x*v.x + u.y*v.y;  
}  
  
// Weather P is On the Segment (uv)   
int dot_on_seg(point p,point u,point v){  
    return dcmp(det(p-u,v-p))==0 && dcmp(dot(p-u,v-p)) >= 0; // '>=' means P is u or v  
}  
// The distance from point p to line l  
double PToLine(point p,line l) {  
    return fabs((p-l.a)*(l.a-l.b))/(l.a-l.b).len();  
}  
// The ProJect Of Point(p) To Line(l)  
point PointProjectLine(point p,line l) {  
    double t = dot(l.b-l.a,p-l.a)/dot(l.b-l.a,l.b-l.a);  
    return l.a + (l.b-l.a)*t;  
}  
  
//}  
// ****************************** First Part end ********************************\\  
  
// Second Part:  
// ********************************* Circle *************************************\\  
// {  
  
struct circle {  
    point O;  
    double r;  
    circle() {};  
    circle(point O,double r):O(O),r(r){};  
};  
  
//}  
// ****************************** Second Part End *******************************\\  
  
// Third Part :  
// ********************************* Polygan *************************************\\  
// {  
  
  
int ConvexHull(vector<point>& p){  
    int n=p.size();  
    int m=0;  
    vector<point> q;  
    q.resize(2*n+5);  
    rep(i,n) {  
        while(m>1 && dcmp((q[m-1]-q[m-2])*(p[i]-q[m-2])) <= 0) m--;  
        q[m++] = p[i];  
    }  
    int k = m;  
    for(int i=n-2;i>=0;i--) {  
        while(m>k && dcmp((q[m-1]-q[m-2])*(p[i]-q[m-2])) <= 0) m--;  
        q[m++] = p[i];  
    }  
    q.resize(m) ;  
    if(m>1) q.resize(m-1);  
    // p = q;    // 是否修改原来的多边形  
    return q.size();  
}  
// 三角形重心  
point Center(point a,point b,point c){  
    return (a+b+c)/3.0;  
}  
// Centroid of Polygan  
point Centroid(vector<point> p){  
    point O(0,0),ret(0,0);  
    int n = p.size();  
    p.pb(p[0]);  
    double area = 0.0;  
    rep(i,n) {  
        ret = ret + Center(O,p[i],p[i+1])*dot(p[i]-O,p[i+1]-O);  
        area += dot(p[i]-O,p[i+1]-O);  
    }  
    if(dcmp(area)==0) {  
        pf("There maybe something wrong\n");  
        return p[0];  
    }  
    return ret / area;  
}  
  
  
struct Polygan{  
    vector<point> g;  
    Polygan() {};  
    Polygan(vector<point> g):g(g){};  
    Polygan(point p[],int n) {g.clear();rep(i,n) g.pb(p[i]); };  
    int convex() { return ConvexHull(g); }  
    point center() { return Centroid(g);  } // 多边形的重心  
};  
  
//}  
// ******************************* Third Part End ********************************\\  
  
  
  
// Sovle Part  
  
int n;  
point p[nMax],a[nMax];  
int in[nMax];  
int od[nMax],f[nMax];  
void adjust(point &u) {  
    if(dcmp(u.x)==0) {  
        if(u.y > 0) u.y = -u.y;  
    }  
}  
inline int small(point u,point v) {  //极角排序  
    if(dcmp(u.x)==0) return dcmp(v.x)!=0;  
    if(dcmp(v.x)==0) return 0;  
    return dcmp(u.y/u.x-v.y/v.x)<0;  
}  
  
inline int equal(point u,point v) {  //极角排序  
    if(dcmp(u.x)==0 || dcmp(v.x)==0) return dcmp(u.x)==0 && dcmp(v.x)==0;  
    return dcmp(u.y/u.x-v.y/v.x)==0;  
}  
int cmp(int i,int j) {  
    return small(a[i],a[j]);  
}  
  
  
  
struct Event{  
    int fr,en;  
    int Count;  
    point v;  
    void make(point p,int a,int b,int c){  
        fr = a;  
        en = b;  
        Count = c;  
        v = p;  
        if(v.x < 0) { v.x=-v.x,v.y=-v.y; }  
        if(dcmp(v.x) == 0) { v.x = 0;if(v.y>0) v.y=-v.y; }  
    }  
};  
  
Event event[nMax];  
int N;  
int on[nMax];  
  
void updata() {  
    int i,j;  
    int tmp = 0;  
    N = 0;  
    for(i=0;i<n-1;) {  
        for(j=i+1;j<n-1;j++)   
            if(!equal(a[od[j]],a[od[i]])) break;  
        event[N].make(a[od[i]],i,j,j-i);  
        N ++;  
        i = j;  
    }  
}  
  
int left(point p,point v) {  
    return dcmp(p*v) < 0;  
}  
  
int deal(int cur){  
    point s=p[cur];  
    rep(i,n) od[i]=i;  
    int k = 0;  
    rep(i,n) if(i!=cur) {  
        a[k] = p[i]-s;  
        on[k++]=in[i];  
    }  
    sort(od,od+k,cmp);  
  
    int w[2]={0};  
    int b[2]={0};  
    updata();  
    //event[0].v.out();  
    for(int i=event[0].en;i<k;i++) {  
        if(left(event[0].v,a[od[i]])){  
            if(on[od[i]]) b[0]++;  
            else w[0]++;  
        }else {  
            if(on[od[i]]) b[1]++;  
            else w[1]++;  
        }  
    }  
    //pf("%d %d %d %d\n",b[0],b[1],w[0],w[1]);  
    int ans = max(event[0].Count + b[0] + w[1] ,\  
                  event[0].Count + b[1] + w[0]);  
    for(int i=1;i<N;i++) {  
        for(int j=event[i-1].fr;j<event[i-1].en;j++) {  
            if(left(event[i].v,a[od[j]])) {  
                if(on[od[j]]) b[0]++;  
                else w[0]++;  
            }else {  
                if(on[od[j]]) b[1]++;  
                else w[1]++;  
            }  
        }  
        for(int j=event[i].fr;j<event[i].en;j++) {  
            if(left(event[0].v,a[od[j]])) {  
                if(on[od[j]]) b[0]--;  
                else w[0]--;  
            }else {  
                if(on[od[j]]) b[1]--;  
                else w[1]--;  
            }  
        }  
        //pf("%d %d %d %d %d\n",b[0],b[1],w[0],w[1],event[i].Count);  
        ans = max(ans,event[i].Count + b[0] + w[1]);  
        ans = max(ans,event[i].Count + b[1] + w[0]);  
    }  
    return ans+1;  
}     

void work() {  
    int ans = 0;  
    rep(i,n) {  
        ans = max(ans,deal(i));  
    }  
    printf("%d\n",ans);  
}  
      
int main() {  
    while(scanf("%d",&n),n){  
        rep(i,n) {  
            p[i].read(),sf("%d",&in[i]);  
        }  
        work();  
    }  
    return 0;  
}  
