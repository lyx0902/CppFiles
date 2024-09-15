#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    int a[501]={0};
    int n;
    int count=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(i!=0) {
            for (int j = 0; j < 501; j++){
                if(a[0]==0&&a[1]==0&&a[2]==0){
                    break;
                }
                if (temp + a[j] == 0) {
                    count++;
                }
            }
        }
        a[i]=temp;
    }
    cout<<count<<endl;
    return 0;
}
