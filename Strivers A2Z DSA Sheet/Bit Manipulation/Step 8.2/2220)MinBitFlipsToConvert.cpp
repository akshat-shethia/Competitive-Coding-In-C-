// link->https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int pop = start ^ goal;
        int count = 0;
        while (pop)
        {
            pop = pop & (pop - 1);
            count++;
        }
        return count;
    }
};