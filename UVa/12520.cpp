#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

typedef long long ll;

inline void calc(ll &N,ll &ret,ll zero,ll two,ll four){
  ret -= min(zero,N) * 0LL;
  N -= min(zero,N);
  ret -= min(two,N) * 2LL;
  N -= min(two,N);
  ret -= min(four,N) * 4LL;
  N -= min(four,N);
}

inline ll compute(ll len,ll N){
  if( len & 1LL ){
    ll ans = 0LL;
    // Pattern 1
    ll half = (len*len) / 2LL + 1LL;
    if( half >= N ) return 4LL * N;
    ll ret = 4LL * half;
    N -= half;

    ll N_tmp = N;
    half--;
    ll zero = 0LL;
    ll two  = ( ( len - 2LL ) / 2LL + 1LL) * 4LL;
    ll four = half - ( zero + two );
    calc(N,ret,zero,two,four);
    ans = ret;

    // Pattern 2
    ret = 4LL * half;
    half++;
    N = N_tmp+1;
    zero = 4LL;
    two  = ( ( len - 2LL ) / 2LL ) * 4LL;
    four = half - ( zero + two );
    calc(N,ret,zero,two,four);
    ans = max(ans,ret);
    return ans;
  } else {
    ll half = (len*len) / 2LL;
    if( half >= N ) return 4LL * N;
    ll ret = 4LL * half;
    N -= half;
    ll zero = 2LL;
    ll two  = ( ( len - 2LL ) / 2LL ) * 4LL;
    ll four = half - ( zero + two );
    calc(N,ret,zero,two,four);
    return ret;
  }

}

int main(){
  ll L,N;
  while( cin >> L >> N, L | N ) cout << compute(L,N) << endl;
  return 0;
}
