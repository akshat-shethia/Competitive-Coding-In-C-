// link->https://leetcode.com/problems/balanced-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    int helper(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int leftHeight = helper(root->left);
        int rightHeight = helper(root->right);
        if (leftHeight == -1 || rightHeight == -1)
            return -1;
        if (abs(leftHeight - rightHeight) > 1)
            return -1;
        return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        int a = helper(root);
        if (a >= 0)
            return true;
        else
            return false;
    }
};