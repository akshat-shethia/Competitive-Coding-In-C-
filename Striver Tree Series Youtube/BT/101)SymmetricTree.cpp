// link->https://leetcode.com/problems/symmetric-tree/

/**
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
    bool sym(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr || right == nullptr)
        {
            return left == right;
        }

        return (left->val == right->val) && sym(left->left, right->right) && sym(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        return sym(root->left, root->right);
    }
};
