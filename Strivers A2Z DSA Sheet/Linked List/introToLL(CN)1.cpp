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

// LINK -> https://www.codingninjas.com/studio/problems/introduction-to-linked-list_8144737?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=SUBMISSION

Node *constructLL(vector<int> &arr)
{
    // dummy node
    Node *dummy = new Node(-1);
    Node *curr = dummy;
    for (int i = 0; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        curr->next = temp;
        curr = curr->next;
    }
    Node *temp = dummy->next;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}