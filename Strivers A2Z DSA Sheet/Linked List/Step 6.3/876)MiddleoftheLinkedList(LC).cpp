// link-> https://leetcode.com/problems/middle-of-the-linked-list/

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *tort = head;
        ListNode *hare = head;
        ListNode *temp = head;
        int count = 0;
        while (temp)
        {
            temp = temp->next;
            count++;
        }

        if (count % 2 == 0)
        {
            while (hare)
            {
                tort = tort->next;
                hare = hare->next->next;
            }
            return tort;
        }
        else
        {
            while (hare->next)
            {
                tort = tort->next;
                hare = hare->next->next;
            }
            return tort;
        }
    }
};