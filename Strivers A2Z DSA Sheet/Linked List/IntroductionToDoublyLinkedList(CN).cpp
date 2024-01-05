/*
 * Definition for doubly-linked list.
 * class Node
 * {
 * public:
 *    int data;
 *    Node *next, *prev;
 *    Node() : data(0), next(nullptr), prev(nullptr) {}
 *    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
 *    Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
 * };
 */

// link -> https://www.codingninjas.com/studio/problems/introduction-to-doubly-linked-list_8160413

Node *constructDLL(vector<int> &arr)
{
    if (arr.empty())
    {
        return nullptr; // Return nullptr for an empty array
    }

    Node *head = new Node(arr[0]);
    Node *temp = head;
    int i = 1;

    while (i < arr.size())
    {
        Node *temp2 = new Node(arr[i]);
        temp->next = temp2;
        temp2->prev = temp;
        temp = temp->next;
        i++;
    }

    return head;
}
