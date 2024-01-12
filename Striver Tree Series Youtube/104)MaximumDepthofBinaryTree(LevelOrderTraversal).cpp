// link->https://leetcode.com/problems/maximum-depth-of-binary-tree/

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

// iterative approach
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        queue<TreeNode *> q;
        vector<vector<int>> ans;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
                level.push_back(temp->val);
            }
            ans.push_back(level);
        }
        return ans.size();
    }
};

// Recursive Approach
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        int level = 0;
        if (root == nullptr)
            return 0;
        level = 1 + max(maxDepth(root->left), maxDepth(root->right));
        return level;
    }
};