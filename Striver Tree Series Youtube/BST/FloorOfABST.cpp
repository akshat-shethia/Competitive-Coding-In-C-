// link->https://www.codingninjas.com/studio/problems/floor-from-bst_625868

#include <climits>
#include <bits/stdc++.h>

int Floor(BinaryTreeNode<int> *node, int x)
{
    int floor = INT_MAX;

    while (node)
    {
        if (node->data > x)
        {
            node = node->left;
        }
        else if (node->data == x)
        {
            return x;
        }
        else
        {
            floor = node->data;
            node = node->right;
        }
    }

    if (floor == INT_MAX)
    {
        return -1;
    }

    return floor;
}
