// link->https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *f(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *&ans)
    {
        if (root == nullptr)
            return nullptr;
        if (root == p || root == q)
            return root;

        TreeNode *leftResult = f(root->left, p, q, ans);
        TreeNode *rightResult = f(root->right, p, q, ans);

        if (leftResult && rightResult)
        {
            ans = root;
            return ans;
        }

        return leftResult ? leftResult : rightResult;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *ans = nullptr;
        ans = f(root, p, q, ans);
        return ans;
    }
};