#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        int mid = sum / 2;

        vector<int> ans;
        for (int i = n - 1; i >= 0 && sum > mid; i--)
        {
            ans.push_back(arr[i]);
            sum -= arr[i];
        }

        int sum1 = 0;
        for (int i = 0; i < n - ans.size()+1; i++)
        {
            sum1+=arr[i];
        }

        int sum2 = 0;
        for (int i = 0; i < ans.size()-1; i++)
        {
            sum2 += ans[i];
        }

        cout << abs(sum1 - sum2) << "\n";
    }

    return 0;
}
