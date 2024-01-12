// link->https://leetcode.com/problems/hamming-distance/

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int ans = x ^ y;
        string s = bitset<32>(ans).to_string();
        int i = 0;
        vector<int> v;

        while (i < s.size())
        {
            if (s[i] == '1')
            {
                v.push_back(i);
            }
            i++;
        }
        return v.size();
    }
};
