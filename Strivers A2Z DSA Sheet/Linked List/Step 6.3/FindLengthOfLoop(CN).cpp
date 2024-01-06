/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/

// link->https://www.codingninjas.com/studio/problems/find-length-of-loop_8160455

int lengthOfLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    Node *temp = head;
    if (head == NULL || head->next == NULL)
        return 0;
    int count = 1;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            while (temp != slow)
            {
                temp = temp->next;
                slow = slow->next;
            }
            temp = temp->next;
            while (temp != slow)
            {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }
    return 0;
}
