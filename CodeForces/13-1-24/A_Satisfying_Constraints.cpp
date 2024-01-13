#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int llo = 0;
        int ul = INT_MAX;
        vector<int> v;

        for (int i = 0; i < n; i++)
        {
            int a, x;
            cin >> a >> x;

            if (a == 1)
                llo = max(llo, x);
            else if (a == 2)
                ul = min(ul, x);
            else
                v.push_back(x);
        }

        int count = max(0, ul - llo + 1);
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] >= llo && v[i] <= ul)
                count--;
        }
        cout << count << endl;
    }

    return 0;
}
