/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() : data(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : data(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : data(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

// link -> https://www.codingninjas.com/studio/problems/delete-last-node-of-a-doubly-linked-list_8160469

Node *deleteLastNode(Node *head)
{
    Node *temp = head;
    if (temp == nullptr || temp->next == nullptr)
        return nullptr;
    while (temp->next->next)
    {
        temp = temp->next;
    }
    temp->next = nullptr;
    return head;
}
