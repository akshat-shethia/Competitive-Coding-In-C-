/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int value;
 *      Node *prev;
 *      Node *next;
 *      Node() : value(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : value(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : value(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

// Link ->https://www.codingninjas.com/studio/problems/insert-at-end-of-doubly-linked-list_8160464

Node *insertAtTail(Node *head, int k)
{
    Node *temp = head;
    Node *temp2 = new Node(k);
    if (temp == nullptr)
        return temp2;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = temp2;
    temp2->prev = temp;
    return head;
}
