// link->https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/

#include <vector>

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < (1 << n); i++) {
            int subsetXOR = 0;
            for (int j = 0; j < n; j++) {
                if ((1 << j) & i)
                    subsetXOR ^= nums[j];
            }
            ans += subsetXOR;
        }
        return ans;
    }
};
