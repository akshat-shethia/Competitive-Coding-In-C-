// link->https://www.codingninjas.com/studio/problems/minimum-element-in-bst_8160462

/*
 * class Node
 * {
 * public:
 *     int data;
 *     Node *left;
 *     Node *right;
 *     Node() : data(0), left(nullptr), right(nullptr){};
 *     Node(int x) : data(x), left(nullptr), right(nullptr) {}
 *     Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
 * };
 */

int minVal(Node *root)
{
    // Base case for empty tree.
    if (!root)
        return -1;

    // Iterating through left child until we reach minimum value.
    while (root->left)
    {
        root = root->left;
    }
    return root->data;
}
