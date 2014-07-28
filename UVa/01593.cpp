#include<bits/stdc++.h>
using namespace std;
const int MAX=1005;

bool dig(char x){return x>='0'&&x<='9';}
int getval()
{
    int ret=0,sign=1;
    char c;
    while(!dig(c=getchar())&&c!='-');
    if(c=='-')sign=-1;
    else ret=c-'0';
    while(dig(c=getchar()))ret=ret*10+c-'0';
    return ret*sign;
}
struct WORD
{
    char s[83];
    int len;
}w[MAX][183];
int m[MAX];
int start[183];
int main()
{
    int n=0;
    int i,j,k;
    char buf[MAX];
    int maxcol=0;
    while(gets(buf))
    {
        m[n]=0;
        for(i=0;buf[i];i++)
        {
            if(buf[i]!=' ')
            {
                j=i;
                k=0;
                while(buf[j]&&buf[j]!=' ')
                {
                    w[n][m[n]].s[k]=buf[j];
                    k++;
                    j++;
                }
                w[n][m[n]].s[k]=0;

                w[n][m[n]].len=k;
                m[n]++;
                i=j-1;
            }
        }
        if(m[n]>maxcol)maxcol=m[n];
        n++;
    }

    start[0]=0;

    for(j=1;j<maxcol;j++)
    {
        start[j]=start[j-1];
        for(i=0;i<n;i++)
        {
            if(m[i]>j-1&&start[j-1]+w[i][j-1].len+1>start[j])
            {
                start[j]=start[j-1]+w[i][j-1].len+1;
            }
        }
    }
    //for(i=0;i<maxcol;i++)printf("start[%d]=%d\n",i,start[i]);
    for(i=0;i<n;i++)
    {
        int cur=0;
        for(j=0;j<m[i];j++)
        {
            while(cur<start[j])
            {
                putchar(' ');
                cur++;
            }

            printf("%s",w[i][j].s);
            cur+=w[i][j].len;
        }
        //if(i<n-1)
            puts("");
    }
    return 0;
}
/*
  start:  integer;    // begins here
stop: integer; //  ends here
 s:  string;
c:   char; // temp


  s:  string;
c:   char; // temp
*/
