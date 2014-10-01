#include <cstdio>
const int MAX_N = 1e6 + 10;

int t[MAX_N];
int a, b, n;
int p[MAX_N];

void update(int i, int x){
  for( ++i; i < MAX_N; i += (i & -i)){
    t[i] += x;
  }
}

int query(int i){
  int sum = 0;
  for(++i; i > 0; i -= (i & -i)){
    sum += t[i];
  }
  return sum;
}

int main(){
  int tc = 1;
  while(scanf("%d%d%d", &n, &a, &b) != EOF){
    if(n + a + b == 0){
      break;
    }
    p[0] = b;
    for(int i = 1; i < n; i++){
      p[i] = (p[i - 1] + a) % n;
    }
    for(int i = 1; i <= n; i++){
      t[i] = 0;
    }
    long long res = 0;
    for(int i = n - 1; i >= 0; i --){
      update(p[i], 1);
      res += query(p[i] - 1);
    }
    printf("Case %d: %lld\n", tc++, res);
  }
  return 0;
}
