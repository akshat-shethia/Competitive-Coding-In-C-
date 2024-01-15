
/**
 link->https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *f(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, unordered_map<int, int> &mp)
    {
        if (is > ie || ps > pe)
            return nullptr;
        TreeNode *temp = new TreeNode(postorder[pe]);
        int curr = mp[temp->val]; // idx of the node
        int nosLeft = curr - is;  // no of nodes on the left
        temp->left = f(inorder, is, curr - 1, postorder, ps, ps + nosLeft - 1, mp);
        temp->right = f(inorder, curr + 1, ie, postorder, ps + nosLeft, pe - 1, mp);
        return temp;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.empty())
            return nullptr;
        int inorderStart = 0;
        int inorderEnd = inorder.size() - 1;
        int postorderStart = 0;
        int postorderEnd = postorder.size() - 1;
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        return f(inorder, inorderStart, inorderEnd, postorder, postorderStart, postorderEnd, mp);
    }
};