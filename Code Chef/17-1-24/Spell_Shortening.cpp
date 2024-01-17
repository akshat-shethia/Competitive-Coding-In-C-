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
        int n;
        cin >> n;
        int k = -1;
        string s;
        cin >> s;
        string ans = "";
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] > s[i + 1])
            {
                k = i;
                break;
            }
        }
        if (k == -1)
            k = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (i != k)
            {
                ans += s[i];
            }
        }

        cout << ans << endl;
    }

    return 0;
}
