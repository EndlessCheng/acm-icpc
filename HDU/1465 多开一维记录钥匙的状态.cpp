#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

#define N 25

bool hash[N][N][1<<10];
char map[N][N];
int n,m,t;
struct node{
    int x,y,s,cnt;
    node(){}
    node(int _x,int _y,int _s,int _cnt){
        x=_x;y=_y;s=_s;cnt=_cnt;
    }
    bool ok(int xx,int yy){
        return x==xx&&y==yy&&cnt<t;
    }
    bool query(int n){
        if(s&(1<<n))return 1;
        return 0;
    }
    void update(int n){
        s|=1<<n;
    }
    void put(){
        printf("%d %d %d %d\n",x,y,s,cnt);
    }
};
int sx,sy,ex,ey;
int move[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int bfs(){
    memset(hash,0,sizeof(hash));
    queue<node>Q;
    node p,q;
    p=node(sx,sy,0,0);
    hash[sx][sy][0]=1;
    Q.push(p);
    while(!Q.empty()){
        p=Q.front();Q.pop();
        if(p.ok(ex,ey)){
            return p.cnt;
        }
        for(int i=0;i<4;i++){
            int x=p.x+move[i][0];
            int y=p.y+move[i][1];
            if(x<0||x>=n||y<0||y>=m)continue;
            if(map[x][y]=='*')continue;
            q=node(x,y,p.s,p.cnt+1);
            if(map[x][y]>='a'&&map[x][y]<='j')
                q.update(map[x][y]-'a');
            if(map[x][y]>='A'&&map[x][y]<='J'&&!q.query(map[x][y]-'A'))continue;
            if(hash[q.x][q.y][q.s])continue;
            Q.push(q);
            hash[q.x][q.y][q.s]=1;
        }
    }
    return -1;
}
int main(){
    while(~scanf("%d%d%d",&n,&m,&t)){
        for(int i=0;i<n;i++){
            scanf("%s",map[i]);
            for(int j=0;j<m;j++){
                if(map[i][j]=='@'){
                    sx=i;sy=j;
                }else if(map[i][j]=='^'){
                    ex=i;ey=j;
                }
            }
        }
        int ans=bfs();
        printf("%d\n",ans);
    }
    return 0;
}
