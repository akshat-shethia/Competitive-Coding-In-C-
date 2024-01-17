// link->https://www.codingninjas.com/studio/problems/search-in-bst_1402878

/*
    Following is the Binary Tree node structure:

    template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };

*/

bool searchInBST(BinaryTreeNode<int> *root, int x)
{
    while (root)
    {
        if (root->data < x)
            root = root->right;
        else if (root->data == x)
            return true;
        else
            root = root->left;
    }
    return false;
}