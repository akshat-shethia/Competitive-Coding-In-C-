#include <iostream>
#include <queue>
#include <map>

using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

template <typename T>
void topView(TreeNode<T> *root)
{
    if (!root)
        return;

    queue<pair<TreeNode<T> *, int>> q;
    map<int, T> topViewMap;

    q.push({root, 0});

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();

        TreeNode<T> *node = current.first;
        int hd = current.second;

        // If the horizontal distance is not in the map, add the node
        if (topViewMap.find(hd) == topViewMap.end())
        {
            topViewMap[hd] = node->data;
        }

        if (node->left)
        {
            q.push({node->left, hd - 1});
        }

        if (node->right)
        {
            q.push({node->right, hd + 1});
        }
    }

    // Print the top view
    for (const auto &entry : topViewMap)
    {
        cout << entry.second << " ";
    }
}

int main()
{
    // Example usage:
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->right = new TreeNode<int>(4);
    root->left->right->right = new TreeNode<int>(5);
    root->left->right->right->right = new TreeNode<int>(6);

    cout << "Top View: ";
    topView(root);

    return 0;
}
