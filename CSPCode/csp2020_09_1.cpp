#include<iostream>
#include<map>
#include<cmath>
using namespace std;

int main(){
    int n,X,Y;
    multimap<int,int> q;//multimap<距离,编号>存最近的三个点的距离及编号
    cin>>n>>X>>Y;//题目输入
    for(int i=0,xi,yi;i<n;++i){//遍历输入的所有监测点坐标
        cin>>xi>>yi;
        int absX = abs(X-xi);
        int absY = abs(Y-yi);
        int distance = absX*absX + absY*absY;//这里避免开平方所取的小数造成判断错误
        q.insert(pair<int,int>(distance,i+1));
        if(q.size()>3){
            q.erase(--q.end());//删掉最后一个元素
        }
    }
    //输出容器内的结果
    for(multimap<int,int>::iterator it = q.begin();it!=q.end();++it){
        cout<<it->second<<endl;
    }
    return 0;
}
