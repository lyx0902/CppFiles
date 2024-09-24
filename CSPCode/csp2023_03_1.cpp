#include <iostream>
#include <vector>

using namespace std;
int a,b;

int main() {
    int n;
    cin >> n >> a >> b;
    int x1, y1, x2, y2;
    int x, y;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        x = min(x2,a) - max(0,x1);
        y = min(y2,b) - max(0,y1);
        if(x >= 0 && y >= 0) {
            sum += x * y;
        }
    }
    cout << sum << endl;
    return 0;
}

