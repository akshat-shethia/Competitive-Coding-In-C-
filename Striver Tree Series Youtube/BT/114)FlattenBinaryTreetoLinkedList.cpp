// link->https://leetcode.com/problems/flatten-binary-tree-to-linked-list/


class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL)return;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode *temp = st.top();
            st.pop();
            if(temp->right)st.push(temp->right);
            if(temp->left)st.push(temp->left);
            if(!st.empty())temp->right = st.top();
            temp->left = nullptr;
        }
    }

};