// link->https://leetcode.com/problems/sort-list/

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *temp123 = new ListNode(-1);
        ListNode *tempc = temp123;
        vector<int> v;
        while (temp)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        sort(v.begin(), v.end());
        temp = head;
        int i = 0;
        while (temp)
        {
            ListNode *temp0 = new ListNode(v[i]);
            tempc->next = temp0;
            tempc = tempc->next;
            temp = temp->next;
            i++;
        }
        return temp123->next;
    }
};