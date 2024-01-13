// link->://www.codingninjas.com/studio/problems/boundary-traversal-of-binary-tree_790725

/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

int isLeaf(TreeNode *node)
{
    TreeNode *temp = node;
    if (temp->left == -1 && temp->right == -1)
        return true;
    return false;
}
void leftTree(TreeNode *node, vector<int> &ans)
{
    TreeNode *temp = node->left;
    while (temp)
    {
        if (!isLeaf(temp))
            ans.push_back(temp->val);
        if (temp->left)
            temp = temp->left;
        else if (temp->right)
            temp = temp->right;
    }
}
void rightTree(TreeNode *node, vector<int> &ans)
{
    TreeNode *temp = node->right;
    vector<int> rev;
    while (temp)
    {
        if (!isLeaf(temp))
            rev.push_back(temp->val);
        if (temp->right)
            temp = temp->right;
        else if (temp->left)
            temp = temp->left;
    }
    for (int i = rev.size() - 1; i >= 0; i--)
    {
        ans.push_back(rev[i]);
    }
}
void inorder(TreeNode *node, vector<int> &ans)
{
    TreeNode *temp = node;
    if (temp == -1)
    {
        ans.push_back(temp);
        return;
    }
    inorder(temp->left, ans);
    inorder(temp->right, ans);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;
    Treenode *node = root[0];
    ans.push_back(node);
}
