// link->https://leetcode.com/problems/detect-capital/

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        if (word.size() == 1)
            return true;
        int a = 0;
        if (isupper(word[0]) && islower(word[1]))
            a = 1;
        else if (isupper(word[0]) && isupper(word[1]))
            a = 2;
        else if (islower(word[0]) && islower(word[1]))
            a = 3;
        else
            return false;

        if (a == 1)
        {
            for (int i = 2; i < word.size(); i++)
            {
                if (isupper(word[i]))
                    return false;
            }
        }
        else if (a == 2)
        {
            for (int i = 0; i < word.size(); i++)
            {
                if (!isupper(word[i]))
                    return false;
            }
        }
        else if (a == 3)
        {
            for (int i = 0; i < word.size(); i++)
            {
                if (isupper(word[i]))
                    return false;
            }
        }
        return true;
    }
};