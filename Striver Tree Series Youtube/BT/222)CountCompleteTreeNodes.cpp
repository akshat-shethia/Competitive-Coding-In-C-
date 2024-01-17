// link->https://leetcode.com/problems/count-complete-tree-nodes/

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
    int count(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);
        if (lh == rh)
            return (1 << lh) - 1; // 1<<h - 1 => 2^h - 1;
        else
            return count(root->left) + count(root->right) + 1;
    }

    int findHeightLeft(TreeNode *root)
    {
        int ht = 0;
        TreeNode *temp = root;
        while (temp)
        {
            ht++;
            temp = temp->left;
        }
        return ht;
    }

    int findHeightRight(TreeNode *root)
    {
        int ht = 0;
        TreeNode *temp = root;
        while (temp)
        {
            ht++;
            temp = temp->right;
        }
        return ht;
    }

    int countNodes(TreeNode *root)
    {
        return count(root);
    }
};
