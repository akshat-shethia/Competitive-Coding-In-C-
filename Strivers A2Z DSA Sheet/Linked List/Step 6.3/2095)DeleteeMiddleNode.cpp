// link->https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        ListNode *temp = head;
        int count = 0;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        if (count == 1)
            return head->next;
        temp = head;
        int n = floor(count / 2.0);
        for (int i = 0; i < n - 1; i++)
            temp = temp->next;
        temp->next = temp->next->next;
        return head;
    }
};
