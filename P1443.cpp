#include<iostream>
#include <cstring>
using namespace std;
int res[402][402];
int dx[8]={2,-2,2,-2,-1,1,-1,1};
int dy[8]={1,1,-1,-1,2,2,-2,-2};
int n,m,x,y;
int check(int x ,int y){
    if(x>n||y>m||x<1||y<1){
        return 0;
    }
    return 1;
}
void dfs(int x,int y,int count){
    int bx,by;
    res[x][y]=count;
    for(int k=0;k<8;k++){
        bx=x+dx[k];
        by=y+dy[k];
        if(check(bx,by)&&(res[bx][by]==-1||count+1<res[bx][by])){
            dfs(bx,by,count+1);
        }
    }
}
int main(){
    cin>>n>>m>>x>>y;
    memset(res,-1,sizeof(res));
    dfs(x,y,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<res[i][j]<<"     ";
        }
        cout<<endl;
    }
    return 0;
}//dfs的应用