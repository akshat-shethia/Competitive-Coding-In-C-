// link->https://leetcode.com/problems/sort-array-by-parity/

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums;
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
                ans.push_back(nums[i]);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 != 0)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};