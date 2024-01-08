/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 */

// link->https://www.codingninjas.com/studio/problems/add-one-to-a-number-represented-as-linked-list_920557
Node *reverse(Node *head)
{
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

Node *addOne(Node *head)
{
    Node *reversed = reverse(head);
    Node *temp = reversed;
    int carry = 1;

    while (temp != nullptr)
    {
        temp->data += carry;
        carry = temp->data / 10;
        temp->data %= 10;

        if (temp->next == nullptr && carry > 0)
        {
            temp->next = new Node(carry);
            break;
        }

        temp = temp->next;
    }

    Node *result = reverse(reversed);
    return result;
}
