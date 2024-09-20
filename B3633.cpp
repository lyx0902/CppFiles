#include <iostream>
#include <set>
using namespace std;
set<int>s1;
set<int>s2;
set<int>combined;
set<int>result;
int main(){
    int x,y;
    cin>>x;
    if(x!=0){
        for(int i=0;i<x;i++){
            int a;
            cin>>a;
            s1.insert(a);
            combined.insert(a);
        }
    }
    cin>>y;
    if(y!=0){
        for(int i=0;i<y;i++){
            int a;
            cin>>a;
            s2.insert(a);
            combined.insert(a);
            for(auto j:s1){
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
    cout<<endl;
    for(int i=0;i<=63;i++){
        if(!s1.contains(i)){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    int flag=1;
    if(s1.size()==s2.size()){
        for(auto i:s1){
            if(!s2.contains(i)){
                flag=0;
                cout<<0<<endl;
                break;
            }
        }
        if(flag==1){
            cout<<1<<endl;
        }
    }
    else{
        cout<<0<<endl;
    }
    flag=1;
    for(auto i:s1){
        if(!s2.contains(i)){
            flag=0;
            cout<<0<<endl;
            break;
        }
    }
    if(flag==1){
        cout<<1<<endl;
    }
    cout<<s1.contains(0)<<endl;
    return 0;
}