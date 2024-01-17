// link->https://leetcode.com/problems/same-tree/submissions/1144343313/

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
    void helper(TreeNode *root, vector<int> &v)
    {
        if (root == nullptr)
        {
            v.push_back(INT_MIN);
            return;
        }
        v.push_back(root->val);
        helper(root->left, v);
        helper(root->right, v);
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr))
            return false;

        vector<int> first, second;
        helper(p, first);
        helper(q, second);

        if (first.size() != second.size())
            return false;

        int n = first.size();
        for (int i = 0; i < n; i++)
        {
            if (first[i] != second[i])
                return false;
        }

        return true;
    }
};

// easier method
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr || q == nullptr)
            return p == q;
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};