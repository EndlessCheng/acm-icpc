#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<string>
#include<map>
#define pi 2*acos(0.0)
#include<algorithm>
using namespace std;
vector<int >a[10000];
void bfs(int x,int y)
{
    queue<int >q;
    bool z[10000];
    string sa[10000];
    memset(z,false,sizeof(z));
    q.push(x);
    z[x]=true;
    sa[x]=64+x;
    //cout<<sa[x];
    while(!q.empty())
    {
        int t=q.front();
        q.pop();int ry=0;
        for(int w=0; w<a[t].size(); w++)
        {
            int s=a[t][w];
            if(z[s]==false)
            {
                z[s]=true;
                char s3=64+s;
                sa[s]=sa[t]+s3;
                q.push(s);
            }
            if(s==y)
            {
                cout<<sa[s]<<endl;ry=1;
                break;
            }


        }

if(ry==1){
    break;

}



    }






}



int main()
{
    unsigned long long i;
    cin>>i;int qw=0;
    for(int t=1; t<=i; t++)
    {qw++;
        if(qw>1)cout<<endl;
        int m,n;
        cin>>m>>n;
        getchar();
        for(int f=1; f<=m; f++)
        {
            char s1[100];
            char s2[100];
            cin>>s1>>s2;
            int x=s1[0]-64;
            int y=s2[0]-64;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for(int f=1; f<=n; f++)
        {
            char s1[1000];
            char s2[1000];
            cin>>s1>>s2;

            int x=s1[0]-64;
            int y=s2[0]-64;
            bfs(x,y);

        }
        for(int f=0; f<=m*2; f++)
        {
            a[f].clear();
        }

    }






    return 0;
}
