#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long LL;

struct node{
    LL n,k;
};

node ans[1000000];
int t,tot;
LL m;

int binomial(LL a,LL b){
    LL aa=1;
    for (LL i=1;i<=a;i++){
        if ((aa+0.0)*(b-i+1)/i>m)
            return 2;
        aa*=b-i+1;
        aa/=i;
    }
    if (aa==m){
        ans[tot].k=a;
        ans[tot].n=b;
        tot++;
        if (a!=b-a){
            ans[tot].k=b-a;
            ans[tot].n=b;
            tot++;
        }
        return 1;
    }
    return 0;

}

bool cmp(const node &a,const node &b){
    if (a.n==b.n)
        return a.k<b.k;
    else
        return a.n<b.n;
}

int main(){
    scanf("%d",&t);
    while (t--){
        scanf("%lld",&m);
        tot=0;
        for (LL i=1;i<=m;i++){
            LL st=(LL)(pow(m,1.0/i));
            st=max(2*i,st);
            if (binomial(i,st)==2)
                break;
            LL l=st,r=m;
            LL mid;
            while (l+1<r){
                mid=(l+r)>>1;
                if (binomial(i,mid))
                    r=mid;
                else
                    l=mid;
            }
        }
        sort(ans,ans+tot,cmp);
        printf("%d\n",tot);
        for (int i=0;i<tot-1;i++){
            printf("(%lld,%lld) ",ans[i].n,ans[i].k);
        }
        printf("(%lld,%lld)\n",ans[tot-1].n,ans[tot-1].k);
    }

}
