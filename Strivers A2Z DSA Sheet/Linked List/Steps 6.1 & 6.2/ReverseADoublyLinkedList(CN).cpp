/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};

*/

// link->https://www.codingninjas.com/studio/problems/reverse-a-doubly-linked-list_1116098

Node *reverseDLL(Node *head)
{
    Node *temp = head;
    Node *prev = nullptr;
    Node *next = nullptr;

    while (temp)
    {
        next = temp->next;
        temp->next = temp->prev;
        temp->prev = next;
        prev = temp;
        temp = next;
    }

    head = prev;

    return head;
}
