#include <iostream>
#include <set>
using namespace std;
set<int>s1;
set<int>s2;
set<int>combined;
set<int>result;
int main(){
    int n,m;
    cin>>n;
    if(n!=0){
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            s1.insert(a);
            combined.insert(a);
        }
    }
    cin>>m;
    if(m!=0){
        for(int i=0;i<m;i++){
            int a;
            cin>>a;
            s2.insert(a);
            combined.insert(a);
            for(auto j=s1.begin();j!=s1.end();j++){
                if(s1.count(a)){
                    result.insert(a);
                }
            }
        }
    }
    cout<<s1.size()<<endl;
    for(auto i:result){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:combined){
        cout<<i<<" ";
    }
    return 0;
}