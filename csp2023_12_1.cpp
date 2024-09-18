#include <iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[1005][11]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];//存储仓库的信息
        }
    }
    for(int i=0;i<n;i++){
        int flag=0;//当前仓库编号
        int temp[11]={0};
        int max1=1020;
        for(int p=0;p<m;p++){
            temp[p]=a[i][p];
        }
        for(int j=0;j<n;j++){
            if(flag!=0){
                break;
            }
            for(int k=0;k<m;k++) {
                if (a[j][k] > temp[k]) {
                    if (k == m - 1) {
                        flag = j + 1;
                    }
                    continue;
                }
                break;
            }
            flag=min(max1,flag);
        }
        cout<<flag<<endl;
    }
    return 0;
}