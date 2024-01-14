// link->https://leetcode.com/problems/binary-tree-right-side-view/

class Solution
{
public:
    void f(TreeNode *root, int level, vector<int> &ans)
    {
        if (root == nullptr)
            return;
        if (level == ans.size())
            ans.push_back(root->val);
        f(root->right, level + 1, ans);
        f(root->left, level + 1, ans);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        TreeNode *temp = root;
        vector<int> ans;
        f(root, 0, ans);
        return ans;
    }
};