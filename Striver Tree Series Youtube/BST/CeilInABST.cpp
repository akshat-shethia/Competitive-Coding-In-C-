// link->https://www.codingninjas.com/studio/problems/ceil-from-bst_920464

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

#include <climits>

int findCeil(BinaryTreeNode<int> *node, int x) {
    int ceil = INT_MAX;

    while (node) {
        if (node->data > x) {
            ceil = node->data;
            node = node->left;
        } else if (node->data == x) {
            return x;
        } else {
            node = node->right;
        }
    }

    if (ceil == INT_MAX) {
        return -1;
    }

    return ceil;
}
