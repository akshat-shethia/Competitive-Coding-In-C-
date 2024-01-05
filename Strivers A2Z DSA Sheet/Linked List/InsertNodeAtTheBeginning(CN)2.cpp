/**
 * Definition of linked list
 * class Node {
 *
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 */

// Link ->https://www.codingninjas.com/studio/problems/insert-node-at-the-beginning_8144739

Node *insertAtFirst(Node *list, int newValue)
{
    Node *temp = new Node(newValue);
    Node *head = list;
    temp->next = head;
    head = temp;
    return head;
}