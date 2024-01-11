// link->https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/

class Solution
{
public:
    int sumIndicesWithKSetBits(vector<int> &nums, int k)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            int a = i;
            while (a)
            {
                a &= (a - 1);
                count++;
            }
            if (count == k)
                sum += nums[i];
        }
        return sum;
    }
};