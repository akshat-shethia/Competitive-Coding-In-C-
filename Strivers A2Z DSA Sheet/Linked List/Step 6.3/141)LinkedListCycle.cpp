// link->https://leetcode.com/problems/linked-list-cycle/

// SC : O(n) because of a stack
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

// SC : O(1) In Place Reordering
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *temp2 = NULL;
        ListNode *prev = NULL;
        while (temp)
        {
            temp2 = temp->next;
            temp->next = prev;
            prev = temp;
            temp = temp2;
        }
        return prev;
    }
};
