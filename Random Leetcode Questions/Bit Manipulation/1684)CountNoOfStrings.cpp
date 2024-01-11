// link->https://leetcode.com/problems/count-the-number-of-consistent-strings/description/

class Solution {
public:
    int countConsistentStrings(string s, vector<string>& words) {
        int count = 0;
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        for (int i = 0; i < words.size(); i++) {
            bool consistent = true;
            for (int j = 0; j < words[i].size(); j++) {
                if (mp.find(words[i][j]) == mp.end()) {
                    consistent = false;
                    break;
                }
            }
            if (consistent) {
                count++;
            }
        }
        
        return count;
    }
};