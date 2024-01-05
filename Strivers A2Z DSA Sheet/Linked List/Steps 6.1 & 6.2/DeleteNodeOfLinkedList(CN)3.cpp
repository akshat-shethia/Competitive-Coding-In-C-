/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

// Link -> https://www.codingninjas.com/studio/problems/delete-node-of-linked-list_8160463

Node *deleteLast(Node *list)
{
    Node *temp = list;
    Node *head = list;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = nullptr;
    return head;
}