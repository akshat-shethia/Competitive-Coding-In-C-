#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"
#define pb emplace_back
#define vi vector<ll>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, k;
    cin >> t >> k;
    unordered_map<int, int> mp;
    vector<int> low(t), hi(t);

    for (int i = 0; i < t; i++)
    {
        cin >> low[i] >> hi[i];
        for (int j = low[i]; j <= hi[i]; j++)
        {
            mp[j]++;
        }
    }

    int oper = 0;
    vector<int> deleted;
    while (!mp.empty())
    {
        int maxi = 0, maxidx = -1;
        for (int i = 0; i < t; i++)
        {
            int count = 0;
            for (int j = low[i]; j <= hi[i]; j++)
            {
                count += mp[j];
            }
            if (count >= maxi)
            {
                maxi = count;
                maxidx = i;
            }
        }

        if (maxidx == -1)
            break;

        for (int j = low[maxidx]; j <= hi[maxidx]; j++)
        {
            mp[j]--;
            if (mp[j] == 0)
                mp.erase(j);
        }

        oper++;
        deleted.push_back(maxidx);
    }

    oper += mp.size();
    cout << oper << endl;
    for (int idx : deleted)
    {
        cout << idx << " ";
    }
    return 0;
}
