

// link->https://www.codingninjas.com/studio/problems/house-robber-ii_839733
#include <bits/stdc++.h>
#define ll long long

int fSpaceOptimised(vector<int> &nums)
{
    // Prev2, prev, curr
    int n = nums.size();
    int prev2 = 0;
    int prev = nums[0];
    for (int i = 1; i < n; i++)
    {
        int selected = nums[i];
        if (i >= 2)
            selected = nums[i] + prev2;
        int NotSelected = 0 + prev;
        int curr = max(NotSelected, selected);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

ll houseRobber(const vector<int>& valueInHouse) {
    int n = valueInHouse.size();
    vector<int> temp1, temp2;
    if(n==1)return valueInHouse[0];
    for (int i = 0; i < n; i++) {
        if (i != 0) temp1.push_back(valueInHouse[i]);
        if (i != n - 1) temp2.push_back(valueInHouse[i]);
    }
    return max(fSpaceOptimised(temp1), fSpaceOptimised(temp2));
}

