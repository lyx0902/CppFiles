#include <iostream>
#include <cstring>
using namespace std;
int n,a,b;
int input[201];
int vis[201];
struct queue1{
    int x;
}c[201];
bool check(int x){
    if(x>n||x<1){
        return false;
    }
    return true;
}
void bfs(int x){//x为当前位置，sum为当前步数
    int head=0,tail=1;
    int sum=0;
    int i=0;
    while(head<tail){
        if(tail==n){
            cout<<-1;
            break;
        }
        if(head==0){
            c[head].x=x;
        }
        int left=c[head].x-input[i];
        int right=c[head].x+input[i];
        if(check(left)&&vis[left]==0){
            if(c[tail].x==b){
                cout<<sum;
                break;
            }
            tail++;
            c[tail].x=left;
            vis[left]=1;
            sum++;
        }
        if(check(right)&&vis[right]==0) {
            if(c[tail].x==b){
                cout<<sum;
                break;
            }
            tail++;
            c[tail].x = right;
            vis[right] = 1;
            sum++;
        }
        i++;
        head++;
        c[head].x=c[tail].x;

    }
}
int main(){
    cin>>n>>a>>b;
    memset(c,-1,sizeof(c));
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    bfs(a);
    return 0;
}