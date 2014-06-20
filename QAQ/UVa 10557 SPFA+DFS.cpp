//Template update date: 20140316
#include <iostream>
#include <sstream>
#include <cstdio>
#include <climits>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#define  esp 1e-6
#define  pi acos(-1.0)
#define  inf 0x0f0f0f0f
#define  pb push_back
#define  lson l, m, rt<<1
#define  rson m+1, r, rt<<1|1
#define  lowbit(x) (x&(-x))
#define  mp(a, b) make_pair((a), (b))
#define  in  freopen("solve_in.txt", "r", stdin);
#define  out freopen("solve_out.txt", "w", stdout);

#define  bug puts("********))))))");
#define  inout in out

#define  SET(a, v) memset(a, (v), sizeof(a))
#define  READ(a, n) {REP(i, n) cin>>(a)[i];}
#define  REP(i, n) for(int i = 0; i < (n); i++)
#define  Rep(i, base, n) for(int i = base; i < n; i++)
#define  REPS(i, s) for(int i = 0; s[i]; i++)
#define  pf(x) ((x)*(x))
#define  Log(a, b) (log((double)b)/log((double)a))
#define Srand() srand((int)time(0))
#define random(number) (rand()%number)
#define random_range(a, b) (int)(((double)rand()/RAND_MAX)*(b-a) + a)

using namespace std;

typedef long long  LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<PII, int> VIII;
typedef VI:: iterator IT;
typedef map<string, int> Mps;
typedef map<int, int> Mpi;
typedef map<int, PII> Mpii;
typedef map<PII, int> Mpiii;

const int maxn = 10000;
int d[maxn], inq[maxn], val[maxn], du[maxn];
VI g[maxn];
int n, flag;

void spfa(int st)
{
    SET(inq, 0);
    d[st] = 100;
    inq[st] = 1;
    queue<int> q;
    q.push(st);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        REP(i, g[u].size()) {
            int v = g[u][i];
            if(v == n) {
                flag = 1;
                return;
            }
            if(d[u]  > d[v] - val[v]) {
                d[v] = d[u] + val[v];
                if(!inq[v]) {
                    inq[v] = 1;
                    q.push(v);
                }
                if(++du[v] > n)
                    d[v] = inf;
                if(du[v] > 3*n + 1)
                    return;
            }
        }
    }
}
int main()
{

    while(scanf("%d", &n), n != -1) {
        flag = 0;
        REP(i, maxn) g[i].clear();
        SET(d, 0), SET(du, 0);
        REP(i, n) {
            scanf("%d", val+i+1);
            int k;
            scanf("%d", &k);
            REP(j, k) {
                int u;
                scanf("%d", &u);
                g[i+1].pb(u);
            }
        }
        if(n == 1)
            puts("winnable");
        else if(n == 0)
            puts("hopeless");
        else {
            spfa(1);
            puts(flag ? "winnable" : "hopeless");
        }
    }
    return 0;
}
