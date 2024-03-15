// link->https://leetcode.com/problems/jump-game/

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int maxIdx = nums[0];
        int i = 1;
        while (i < nums.size())
        {
            if (maxIdx < i) // If we cannot reach index 'i' from any previous index
                return false;
            maxIdx = max(maxIdx, i + nums[i]); // Update max index we can reach
            ++i;
        }
        return true;
    }
};
