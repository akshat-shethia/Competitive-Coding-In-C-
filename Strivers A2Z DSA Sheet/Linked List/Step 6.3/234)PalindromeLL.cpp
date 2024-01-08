// link->https://leetcode.com/problems/palindrome-linked-list/

class Solution
{
public:
    ListNode *rev(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *reversedList = new ListNode(-1);
        ListNode *tempReversed = reversedList;
        stack<int> st;

        while (temp)
        {
            st.push(temp->val);
            temp = temp->next;
        }

        while (!st.empty())
        {
            ListNode *tempNode = new ListNode(st.top());
            tempReversed->next = tempNode;
            tempReversed = tempReversed->next;
            st.pop();
        }

        return reversedList->next;
    }
    bool isPalindrome(ListNode *head)
    {
        ListNode *tempa = head;
        ListNode *temp2 = head;
        ListNode *tempb = rev(temp2);
        while (tempa && tempb)
        {
            if (tempa->val != tempb->val)
                return false;
            tempa = tempa->next;
            tempb = tempb->next;
        }
        return true;
    }
};