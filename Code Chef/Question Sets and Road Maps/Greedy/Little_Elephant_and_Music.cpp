#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        vector<int> ln;

        for (int i = 0; i < n; i++)
        {

            cin >> v[i].first >> v[i].second;
        }
        sort(v.begin(), v.end());

        long long int sum = 0, total = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i == 0 || v[i - 1].first < v[i].first)
            {
                ln.push_back(v[i].second);
            }
            else
                total += v[i].second;
        }

        sum += total * ln.size();

        sort(ln.begin(), ln.end());

        for (int i = 0; i < ln.size(); ++i)
        {
            sum += (long long int)(i + 1) * ln[i];
        }
        cout << sum << endl;
    }
}