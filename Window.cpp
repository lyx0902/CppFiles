#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Window {
    int x1, y1, x2, y2, id;
};

inline bool isInside(int x, int y, const Window& window) {
    return x >= window.x1 && x <= window.x2 && y >= window.y1 && y <= window.y2;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Window> windows(N);
    vector<int> results(M);

    for (int i = 0; i < N; ++i) {
        cin >> windows[i].x1 >> windows[i].y1 >> windows[i].x2 >> windows[i].y2;
        windows[i].id = i;
    }

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        bool found = false;
        for (int j = N - 1; j >= 0; --j) {
            if (isInside(x, y, windows[j])) {
                results[i] = windows[j].id + 1;
                swap(windows[j], windows[N - 1]);
                windows.pop_back();
                windows.push_back(windows[N - 1]);
                found = true;
                break;
            }//用vector来模拟窗口被点击的入栈出栈
        }
        if (!found) {
            results[i] = -1; // -1表示ignored
        }
    }

    for (int i = 0; i < M; ++i) {
        if (results[i] == -1) {
            cout << "IGNORED" << endl;
        } else {
            cout << results[i] << endl;
        }
    }

    return 0;
}