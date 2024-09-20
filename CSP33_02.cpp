#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n,m;
string s1[10010];
string s2[10010];
set <string> word1;
set <string> word2;
set <string> combined;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s1[i];
        transform(s1[i].begin(),s1[i].end(),s1[i].begin(),::tolower);  //把所有字符串都变成小写
        word1.insert(s1[i]);
    }
    for(int i=1;i<=m;i++){
        cin>>s2[i];
        transform(s2[i].begin(),s2[i].end(),s2[i].begin(),::tolower);  //把所有字符串都变成小写
        word2.insert(s2[i]);
    }
    set <string>::iterator it;
    for(it=word1.begin();it!=word1.end();it++){
        combined.insert(*it);
    }
    for(it=word2.begin();it!=word2.end();it++){
        combined.insert(*it);
    }
    cout<<word1.size()+word2.size()-combined.size()<<endl;
    cout<<combined.size();
    return 0;
}
