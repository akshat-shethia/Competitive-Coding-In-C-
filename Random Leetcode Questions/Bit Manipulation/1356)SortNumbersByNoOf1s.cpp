// link->https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

class Solution
{
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.second == b.second)
        {
            return a.first < b.first;
        }
        return a.second < b.second;
    }
    vector<int> sortByBits(vector<int> &arr)
    {
        vector<pair<int, int>> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            int x = arr[i];
            int count = 0;
            while (x)
            {
                x = (x & (x - 1));
                count++;
            }
            mp.push_back({arr[i], count});
        }
        vector<int> ans;
        sort(mp.begin(), mp.end(), cmp);
        for (auto ele : mp)
        {
            int num = ele.first;
            ans.push_back(num);
        }
        return ans;
    }
};