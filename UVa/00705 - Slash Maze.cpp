#include <iostream>
#include <cstring>
#define max 80
using namespace std;
int data[max*3][max*3], vis[max*3][max*3], flag, w, h, sum;
void dfs(int i, int j)
{
    if(i<0||i>=3*h||j<0||j>=3*w){flag = 0; return;}
    if(data[i][j]||vis[i][j])return;
    vis[i][j] = 1;
    sum++;
    dfs(i-1,j);
    dfs(i,j-1);
    dfs(i,j+1);
    dfs(i+1,j);
}
int main ()
{
    int m, n, count = 0;
    while(cin>>w>>h&&w&&h)
    {
        cin.get();
        memset(data,0,sizeof(data));
        memset(vis,0,sizeof(vis));
        m = sum = n = 0;
        for(int i = 0; i < 3*h; i+=3,cin.get())
        for(int j = 0; j < 3*w; j+=3)
        {
            char ch = cin.get();
            if(ch == '\\')
            data[i][j] = data[i+1][j+1] = data[i+2][j+2]= 1;
            else if(ch == '/')
            data[i][j+2] = data[i+1][j+1] = data[i+2][j]= 1;
        }
        for(int i = 0; i < 3*h; i++)
        for(int j = 0; j < 3*w; j++)
        {
            if(!vis[i][j]&&!data[i][j])
            {
            flag = 1;
            dfs(i,j);
            n+=flag;
            m = (m<sum&&flag)?sum:m;
            sum = 0;
            }
        }
        cout<<"Maze #"<<++count<<":"<<endl;
        if(n)cout<<n<<" Cycles; the longest has length "<<m/3<<".\n\n";
        else cout<<"There are no cycles.\n\n";
    }
    return 0;
}
