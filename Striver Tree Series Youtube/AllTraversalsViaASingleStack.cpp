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

//                               BASIC EXPLANATION
//  IN A STACK TAKE A PAIR OF {NODE, NUM}AS INPUT, NUM WILL BE 1 AT THE STARTING
// WHILE EXPLORING TAKE OUT EACH ELEMENT IN THE STACK AND INCREASE ITS NUM AND PUSH IT BACK INTO THE STACK
// WHEN NUM == 1 (PUSH_BACK INTO PREORDER VECTOR), WHEN NUM == 2 (PUSH_BACK INTO INORDER VECTOR), WHEN NUM == 3 (PUSH_BACK INTO POSTORDER VECTOR)
// WHILE THE NUM == 1, INCLUDE THE LEFT NODES AS WELL AND WHILE THE NUM == 2 INCLUDE THE RIGHT NODES, WHILE NUM == 3 JUST PB INTO THE VECTOR
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<pair<TreeNode *, int>> st;
        vector<int> pre;
        vector<int> in;
        vector<int> post;
        if (root == nullptr)
            return pre;
        st.push({root, 1});
        while (!st.empty())
        {
            auto temp = st.top();
            st.pop();
            if (temp.second == 1)
            {
                pre.push_back(temp.first->val);
                temp.second++;
                st.push(temp);
                if (temp.first->left)
                    st.push({temp.first->left, 1});
            }
            else if (temp.second == 2)
            {
                in.push_back(temp.first->val);
                temp.second++;
                st.push(temp);
                if (temp.first->right)
                    st.push({temp.first->right, 1});
            }
            else
                post.push_back(temp.first->val);
        }
        return pre;
    }
};