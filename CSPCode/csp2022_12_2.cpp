#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main() {
    int n, m;
    map<int, int>maps;        //有序哈希表存储第i项科目依赖的科目
    cin >> n >> m;
    vector<int>days;          //存储训练第i项科目需要天数
    vector<int>prime;         //存储最早开始时间
    vector<int>last(101,n);   //存储最晚开始时间，默认假设m（数据格式m最大值为101）项科目都是最晚（n天）开始的。长度为101，
    bool flag = true;         //标记是否能在n天内完成全部m项科目的训练
    for (int i = 0; i < m; ++i) {  //科目编号为key，从0开始。依赖科目编号为value，value为-1表示没有依赖
        int j;
        cin >> j;
        maps[i] = j - 1;
    }
    for (int i = 0; i < m; ++i) {   //训练第i项科目需要的天数
        int j;
        cin >> j;
        days.push_back(j);
    }
    for (int i = 0; i < m; ++i) {   //从前往后记录每项科目的最早开始时间
        if (maps[i] == -1)          //没有依赖的项目最早开始时间就是第一天
            prime.push_back(1);
        else {                      //有依赖的项目最早开始时间为依赖项目的最早开始时间+完成依赖项目需要的时间
            int day = prime[maps[i]] + days[maps[i]];
            prime.push_back(day);
            if (day + days[i] > n)   //当前项目的最早开始时间+它完成时间超过n天，表明不能在比赛开始前完成训练，标记标志位为false
                flag = false;
        }
    }
    for (int i = 0; i < prime.size(); ++i)  //输出最早开始时间
        cout << prime[i] << " ";
    cout << endl;
    if (flag) {                       //比赛开始前可以完成项目训练
        for (int i = m - 1; i >= 0; --i) {   //从后往前记录最晚开始时间
            last[i] -= days[i];              //最晚也要完成当前项目的训练时间，用暂定最晚开始时间减去当前项目的训练时间
            int day = last[i];               //定义变量day记录当前项目最晚开始时间
            /*
                ！！！！！！！！！！！重点！！！！！！！！！！！
                由于被依赖项目的最晚开始时间受依赖它的项目的最晚开始时间影响
                因此若一个项目有依赖项目（依赖项目编号一定在它前面），
                则其依赖项目的最晚开始时间至少和它的最晚开始时间一样。
                所以一个项目有依赖，更新被依赖项目最晚开始时间（（暂定，不考虑自身的训练时间））和它的一样。

                此时会遇到一个问题：有两个项目依赖同一个项目。
                解决办法：首先这两个项目之间不可能存在依赖关系，它俩可以并行训练。
                        被依赖项目的最晚开始时间（暂定，不考虑自身的训练时间）此时取决于这两个项目哪一个的训练时间长，
                        也就是让被赖项目的最晚开始时间（暂定，不考虑自身的训练时间）尽可能的小。
                举个例子
                        假设被依赖项目x完成自身训练需要1天  刚开始默认所有项目最晚开始时间为20
                        有两个项目a，b依赖x，b的编号大于a。a，b两个项目的完成自身训练需要4、3天，则最晚开始时间为16，17天。
                        从后往前遍历，x最先受b影响，17<20，x最晚开始时间为17，接着又受a影响，16<17，x最晚开始时间为16。
            */
            if (maps[i] != -1) {
                last[maps[i]] = day > last[maps[i]] ? last[maps[i]] : day;  //maps[i]表示被依赖项目编号。last[maps[i]]表示被依赖项目最晚开始时间
            }
        }
        for (int i = 0; i < m; i++)   //输出最晚开始时间，由于上一步相减操作中没有考虑多减一天的影响，输出的时候加上这一天
        {
            cout << last[i] + 1 << " ";
        }
        cout << endl;
    }

}