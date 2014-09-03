#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 102
char a[N],b[N];
int tt,t,n;

int main(){
  int i,s0,s1,ss,ss1;
  scanf("%d",&t);
  for (tt=1;tt<=t;++tt){
    printf("Case %d: ",tt);
    scanf("%s%s",a,b);
    n=strlen(a);
    s0=s1=ss=ss1=0;
    for (i=0;i<n;++i){
      if (a[i]=='0' && b[i]=='1') ++s0;
      if (a[i]=='1' && b[i]=='0') ++s1;
      if (a[i]=='?'){
        if (b[i]=='1') ++ss1;
        ++ss;
      }
    }
    if (s1>s0+ss1) puts("-1");
    else printf("%d\n",max(s0,s1)+ss);
  }
  return 0;
}
