// link->https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class Solution
{
public:
    TreeNode *f(vector<int> &inorder, int is, int ie, vector<int> &preorder, int ps, int pe, unordered_map<int, int> &mp)
    {
        if (is > ie || ps > pe)
            return nullptr;
        TreeNode *temp = new TreeNode(preorder[ps]);
        int curr = mp[temp->val]; // idx of the node
        int nosLeft = curr - is;  // no of nodes on the left
        temp->left = f(inorder, is, curr - 1, preorder, ps + 1, ps + nosLeft, mp);
        temp->right = f(inorder, curr + 1, ie, preorder, ps + 1 + nosLeft, pe, mp);
        return temp;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int inorderStart = 0;
        int inorderEnd = inorder.size() - 1;
        int preorderStart = 0;
        int preorderEnd = preorder.size() - 1;
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        return f(inorder, inorderStart, inorderEnd, preorder, preorderStart, preorderEnd, mp);
    }
};