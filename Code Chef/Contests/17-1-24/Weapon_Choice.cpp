#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int h, x, y1, y2, k;
        cin >> h >> x >> y1 >> y2 >> k;
        int gun = ceil(static_cast<double>(h) / x);
        int sw = min(k, static_cast<int>(ceil(static_cast<double>(h) / y1)));
        h -= y1 * sw;
        if (h > 0)
            sw += static_cast<int>(ceil(static_cast<double>(h) / y2));
        cout << min(gun, sw) << endl;
    }

    return 0;
}
