# link->https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution(object):
    def reverseWords(self, s):
        list1 = s.split(' ')
        ans = ''
        for i in list1:
            ans = ans + i[::-1] + ' '
        return ans[:len(ans) - 1]
