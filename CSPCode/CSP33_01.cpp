#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int cnt[101],sum[101],length[101];//cnt:单词出现次数,sum:单词包含文章数
    int y[101][101],judge[101][101];
    memset(y,0,sizeof(y));
    memset(judge,0,sizeof(judge));
    memset(cnt,0,sizeof(cnt));
    memset(length,0,sizeof(length));
    memset(sum,0,sizeof(sum));
    for(int i=0;i<n;i++){
        cin>>length[i];
        for(int j=0;j<length[i];j++){
            int f;
            cin>>f;
            y[i][j]=f;
            if(judge[i][f]==0){
                judge[i][f]+=1;
                cnt[f]+=1;
            }
            sum[f]+=1;
        }
    }
    for(int i=1;i<=m;i++) {
        cout << cnt[i] << " " << sum[i] << endl;
    }
    return 0;
}