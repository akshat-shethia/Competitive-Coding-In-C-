/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

// link->https://www.codingninjas.com/studio/problems/sort-linked-list-of-0s-1s-2s_1071937

Node *sortList(Node *head)
{
    Node *temp = head;
    Node *temp21 = new Node(-1);
    Node *tempc = temp21;
    vector<int> v;
    while (temp)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }
    sort(v.begin(), v.end());
    temp = head;
    int i = 0;
    while (temp)
    {
        Node *temp2 = new Node(v[i]);
        tempc->next = temp2;
        tempc = tempc->next;
        temp = temp->next;
        i++;
    }
    return temp21->next;
}