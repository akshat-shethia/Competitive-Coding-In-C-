// link-> https://leetcode.com/problems/linked-list-cycle-ii/description/

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *temp = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                // DISTANCE OF TEMP FROM CYCLIC NODE IS THE SAME AS THE DISTANCE OF THE SLOW / FAST POINTER FROM THE CYCLIC NODE
                // THEREFORE TEMP AND SLOW WILL MEET AT THE DESIRED POINT ( STARTING OF THE CYCLE )
                while (temp != slow)
                {
                    temp = temp->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};