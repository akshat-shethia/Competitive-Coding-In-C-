// link->https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head;
        int count = 0;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        int positionToRemove = count - n + 1;
        if (positionToRemove == 1)
        {
            head = head->next;
            return head;
        }

        temp = head;
        for (int i = 0; i < positionToRemove - 2; i++)
        {
            temp = temp->next;
        }
        if (temp->next == nullptr)
        {
            return nullptr;
        }

        temp->next = temp->next->next;
        return head;
    }
};
