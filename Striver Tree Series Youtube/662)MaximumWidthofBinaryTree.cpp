// link->https://leetcode.com/problems/maximum-width-of-binary-tree/description/

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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        queue<pair<TreeNode *, long long>> q;
        int ans = 0;
        q.push({root, 0});
        while (!q.empty())
        {
            int size = q.size();
            long long number = q.front().second;
            long long first = 0;
            long long last = 0;
            for (int i = 0; i < size; i++)
            {
                long long currId = q.front().second - number;
                TreeNode *temp = q.front().first;
                q.pop();
                if (i == 0)
                    first = currId;
                if (i == size - 1)
                    last = currId;
                if (temp->left)
                    q.push({temp->left, 2 * currId + 1});
                if (temp->right)
                    q.push({temp->right, 2 * currId + 2});
            }
            ans = max(ans, static_cast<int>(last - first + 1));
        }
        return ans;
    }
};
