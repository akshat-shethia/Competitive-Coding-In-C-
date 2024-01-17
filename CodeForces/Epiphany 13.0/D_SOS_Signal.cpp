#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        int x = a + c;
        int y = b + d;
        bool flag = false;

        while (x <= y)
        {
            while (x <= y)
            {
                x += c;
                if (x == y)
                {
                    flag = true;
                    break;
                }
            }

            if (flag)
            {
                break;
            }

            y += d;
        }

        if (flag == false)
            cout << -1 << endl;
        else
            cout << x << endl;
    }

    return 0;
}
