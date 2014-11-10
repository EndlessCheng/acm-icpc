#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
#include <complex>
using namespace std;

#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define ACCU accumulate
#define TWO(x) (1<<(x))
#define TWOL(x) (1ll<<(x))
#define clr(a) memset(a,0,sizeof(a))
#define POSIN(x,y) (0<=(x)&&(x)<n&&0<=(y)&&(y)<m)
#define PRINTC(x) cout<<"Case #"<<++__<<": "<<x<<endl 
#define POP(x) (__builtin_popcount(x))
#define POPL(x) (__builtin_popcountll(x))
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef complex<double> CD;
const int inf=0x20202020;
const ll mod=1000000007;
const double eps=1e-9;
const double pi=3.1415926535897932384626;
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

inline int getint() {
    int ret=0;bool ok=0,neg=0;
    for(;;) {
        int c=getchar();
        if(c>='0'&&c<='9')ret=(ret<<3)+ret+ret+c-'0',ok=1;
        else if(ok)return neg?-ret:ret;
        else if(c=='-')neg=1;
    }
}

const int N=101000;
int n,m,k,x,v,l[N],r[N],id[N],cx[N];
pair<pair<int,LD>,int> p[N];
LD c[N],ans;
vector<PII> vec;

LD query(int x) { LD s=0; for (;x;x-=x&-x) s+=c[x]; return s;}
void modify(int x,LD s) { for (;x<=n;x+=x&-x) c[x]+=s;}
int query(int l,int r) {
    return upper_bound(cx,cx+n,r)-lower_bound(cx,cx+n,l);
}
int main() {
    for (int T=getint();T;T--) {
        n=getint(); m=getint();
        rep(i,0,n) {
            x=getint(); v=getint();
            p[i]=mp(mp(x,v),i);
        }
        sort(p,p+n);
        rep(i,0,n) id[p[i].se]=i;
        rep(i,0,n) cx[i]=p[i].fi.fi;
        rep(i,1,n+1) c[i]=0;
        rep(i,1,n+1) modify(i,p[i-1].fi.se);
        ans=0;
        rep(i,0,m) {
            x=id[getint()-1]; k=getint();
            int l=0,r=1000010000,pl=0,pr=0;
            while (l+1<r) {
                int md=(l+r)>>1;
                if (query(cx[x]-md,cx[x]+md)>=k+1) r=md; else l=md;
            }
            pr=upper_bound(cx,cx+n,cx[x]+r)-cx-1;
            pl=lower_bound(cx,cx+n,cx[x]-r)-cx;
            if (pr-pl!=k) {
                if (p[pl].se<p[pr].se) --pr; else ++pl;
            }
            LD e=(query(pr+1)-query(pl)-p[x].fi.se)/k;
            ans+=e;
            modify(x+1,e-p[x].fi.se);
            p[x].fi.se=e;
        }
        printf("%.3f\n",(double)ans);
    }
}
