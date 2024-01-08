/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(NULL) {}
 *     ListNode(int x) : val(x), next(NULL) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// link->https://leetcode.com/problems/add-two-numbers/
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *c = new ListNode(-1);
        ListNode *tempC = c;
        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry != 0)
        {
            int sum = carry;

            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            tempC->next = new ListNode(sum % 10);
            tempC = tempC->next;

            carry = sum / 10;
        }

        return c->next;
    }
};