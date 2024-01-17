// link->https://www.codingninjas.com/studio/problems/children-sum-property_8357239

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/
bool f(Node *root)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }

    int childrenSum = 0;
    if (root->left)
    {
        childrenSum += root->left->data;
    }
    if (root->right)
    {
        childrenSum += root->right->data;
    }

    if (root->data != childrenSum)
    {
        return false;
    }

    return f(root->left) && f(root->right);
}

bool isParentSum(Node *root)
{
    if (root && root->left == NULL && root->right == NULL)
    {
        return false;
    }

    return f(root);
}
