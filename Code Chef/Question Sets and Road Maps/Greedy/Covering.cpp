#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> intervals;
    for (int i = 0; i < n; ++i)
    {
        pair<int, int> p;
        cin >> p.first >> p.second;
        intervals.push_back(p);
    }

    sort(intervals.begin(), intervals.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second < b.second; });

    int smallestSetSize = 0;
    int currentEnd = INT_MIN;

    for (int i = 0; i < n; ++i)
    {
        if (intervals[i].first > currentEnd)
        {
            ++smallestSetSize;
            currentEnd = intervals[i].second;
        }
    }

    cout << smallestSetSize << endl;
    return 0;
}
