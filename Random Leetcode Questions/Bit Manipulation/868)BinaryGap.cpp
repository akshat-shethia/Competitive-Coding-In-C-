// link->https://leetcode.com/problems/binary-gap/description/

class Solution
{
public:
    int binaryGap(int n)
    {
        int maxDistance = 0;
        int lastOnePos = -1;
        int currentPosition = 0;

        while (n > 0)
        {
            if (n & 1)
            {
                if (lastOnePos != -1)
                {
                    maxDistance = max(maxDistance, currentPosition - lastOnePos);
                }
                lastOnePos = currentPosition;
            }
            n >>= 1;
            currentPosition++;
        }

        return maxDistance;
    }
};
