#include<iostream>
using namespace std;
const int N = 20;
int n;
char g[N][N];//path是各个位置上的数的位置
bool col[N], dg[N], udg[N];//dg正对角线，udg反对角线
//u=i就是第i层
//目前这个没有优化的
struct chess {
    int a[15];//存储皇后位置的列号
}ccc[15];
int gggg=0;//整个循环的第几次

void dfs(int u) {
    if (u == n) {
        if (gggg <= 2) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (g[i][j] == 'Q') {
                        ccc[gggg].a[i] = j;
                    }
                }
            }
        }

        gggg++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!col[i] && !dg[u + i] && !udg[n - u + i]) {//这行没有放过并且两个对角线也没有放过皇后
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1);//递归函数
            col[i] = dg[u + i] = udg[n - u + i] = false;
            //恢复现场
            g[u][i] = '.';
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = '.';
        }
    }
    dfs(0);//u传入的是列的数据
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            ccc[i].a[j] += 1;
            cout << ccc[i].a[j] << " ";
        }
        cout << endl;
    }
    cout << gggg;
    return 0;
}
//第一种解法：暴力搜索 按行枚举
//时间复杂度 2的n?次方