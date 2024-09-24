#include <iostream>
#include <cstring>
using namespace std;
int res[402][402];
bool vis[402][402];
int dx[8]={2,-2,2,-2,-1,1,-1,1};
int dy[8]={1,1,-1,-1,2,2,-2,-2};
int n,m,x,y;
struct queue1{
    int x,y;
}q[40001];
int check(int x ,int y){
    if(x>n||y>m||x<1||y<1){
        return 0;
    }
    return 1;
}
void bfs(int x,int y){
    int head=0,tail=1,sum=0;
    q[1].x=x;
    q[1].y=y;
    vis[x][y]=1;
    res[x][y]=0;
    while(head<tail){
        head++;
        sum=res[q[head].x][q[head].y]+1;
        for(int i=0;i<8;i++){
            int bx=q[head].x+dx[i];
            int by=q[head].y+dy[i];
            if(check(bx,by)&&!vis[bx][by]){
                tail++;
                q[tail].x=bx;
                q[tail].y=by;
                vis[bx][by]=1;
                res[bx][by]=sum;
            }
        }
    }
}
int main(){
    cin>>n>>m>>x>>y;
    memset(res,-1,sizeof(res));
    bfs(x,y);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<res[i][j]<<"     ";
        }
        cout<<endl;
    }
    return 0;
}
