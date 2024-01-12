// link->https://leetcode.com/problems/counting-bits/

#define ll long long
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> v;
        for (int i = 0; i <= n; i++)
        {
            int a = i;
            ll count = 0;
            while (a)
            {
                count++;
                a = a & (a - 1);
            }
            v.push_back(count);
        }
        return v;
    }
};