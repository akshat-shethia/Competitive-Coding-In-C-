#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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

        vector<int> gifts(n);
        vector<int> sortedPositions(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> gifts[i];
            sortedPositions[i] = gifts[i];
        }

        sort(sortedPositions.begin(), sortedPositions.end());

        unordered_map<int, int> positionMap;

        for (int i = 0; i < n; ++i)
        {
            positionMap[sortedPositions[i]] = i;
        }

        int swaps = 0;

        for (int i = 1; i < n; ++i)
        {
            if (positionMap[gifts[i - 1]] > positionMap[gifts[i]])
            {
                swaps++;
            }
        }

        cout << swaps << endl;
    }

    return 0;
}
