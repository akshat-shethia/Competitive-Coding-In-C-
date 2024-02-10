// link->https://leetcode.com/problems/lemonade-change/

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        unordered_map<int, int> mp;
        for (int bill : bills)
        {
            if (bill == 5)
            {
                mp[5]++;
            }
            else if (bill == 10)
            {
                if (mp[5] == 0)
                    return false;
                mp[5]--;
                mp[10]++;
            }
            else if (bill == 20)
            {
                if (mp[10] > 0 && mp[5] > 0)
                {
                    mp[10]--;
                    mp[5]--;
                }
                else if (mp[5] >= 3)
                {
                    mp[5] -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
