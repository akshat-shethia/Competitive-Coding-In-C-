// link->https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    vector<int> helper(TreeNode *root, vector<int> &v)
    {
        if (root == nullptr)
            return v;
        helper(root->left, v);
        helper(root->right, v);
        v.push_back(root->val);
        return v;
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> v;
        vector<int> ans = helper(root, v);
        return ans;
    }
};