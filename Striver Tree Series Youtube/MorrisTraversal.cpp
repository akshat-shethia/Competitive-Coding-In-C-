// link->https://leetcode.com/problems/binary-tree-inorder-traversal/

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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if (root == nullptr)
            return v;
        TreeNode* curr = root;
        while(curr != nullptr){
            if(curr->left == nullptr){
                v.push_back(curr->val);
                curr = curr->right;
            }
            else{ //curr->left != nullptr hence we have to make manual connections
            TreeNode *temp = curr->left;
                while(temp->right && temp->right != curr){
                    temp = temp->right;
                }
                if(temp->right == nullptr){
                    temp->right = curr; // Connection has been made
                    curr = curr->left;
                }
                else{ // temp->right == curr
                    temp->right = nullptr;
                    v.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return v;
    }
};