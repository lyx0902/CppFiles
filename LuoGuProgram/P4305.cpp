#include <iostream>
#include <cstring>
using namespace std;
int main(){
    #define int long long
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    int a[50005];
    for(int i=0;i<t;i++){
        memset(a,0,sizeof(a));
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            int k;
            cin>>k;
            if(a[k]==0){
                a[k]=1;
                cout<<k<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}