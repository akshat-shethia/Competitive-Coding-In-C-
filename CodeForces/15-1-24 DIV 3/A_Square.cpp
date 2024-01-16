#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> x(4);
        vector<int> y(4);

        for (int i = 0; i < 4; ++i) {
            cin >> x[i] >> y[i];
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        int x1 = x[0];
        int x2 = x[3];
        int x3 = x[1];
        int x4 = x[2];
        int y1 = y[0];
        int y2 = y[3];
        int y3 = y[1];
        int y4 = y[2];

        int area = (x2 - x1) * (y2 - y1);
        cout << area << endl;
    }

    return 0;
}
