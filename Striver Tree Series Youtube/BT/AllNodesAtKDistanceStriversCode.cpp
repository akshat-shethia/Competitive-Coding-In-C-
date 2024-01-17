#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Class to find nodes at a
// distance K from a target node
class Solution {
    
    // Helper function to mark parents
    // of nodes in the tree
    void markParents(TreeNode *root, unordered_map<TreeNode*,
        TreeNode*> &parent_track, TreeNode* target) {
        
        // Level Order Traversal by taking a queue
        queue<TreeNode*> queue;
        queue.push(root);
        
        // Iterate over all nodes
        while (!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();
            
            // Assign parents to left child and
            // right child if they exist
            if (current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            
            if (current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }

public:
    // Function to find nodes at a
    // distance K from the target node
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        // Map to mark the parents of all nodes
        unordered_map<TreeNode*, TreeNode*> parent_track;
        // Mark parents of all nodes
        markParents(root, parent_track, target); 
        // Keeps track of visited nodes
        unordered_map<TreeNode*, bool> visited; 
        // Queue to perform level-order traversal
        queue<TreeNode*> queue; 
         // Start traversal from the target node
        queue.push(target);
        // Tracks the current level
        // while traversing the tree
        int curr_level = 0; 
        
        // Continue traversal until the queue is empty
        while (!queue.empty()) { 
            // Get the number of nodes at the current level
            int size = queue.size(); 
            if (curr_level++ == k) { 
                // Break if the current level
                // matches the required distance (k)
                break;
            }
            
            // Traverse the current level of the tree
            for (int i = 0; i < size; i++) {
                // Get the front node in the queue
                TreeNode* current = queue.front(); 
                // Remove the front node from the queue
                queue.pop(); 
                
                // Add unvisited left child to the queue
                if (current->left && !visited[current->left]) {
                    queue.push(current->left);
                    // Mark left child as visited
                    visited[current->left] = true; 
                }
                
                // Add unvisited right child to the queue
                if (current->right && !visited[current->right]) {
                    queue.push(current->right);
                     // Mark right child as visited
                    visited[current->right] = true;
                }
                
                // Add unvisited parent node to the queue
                if (parent_track[current] && !visited[parent_track[current]]) {
                    queue.push(parent_track[current]);
                    // Mark parent node as visited
                    visited[parent_track[current]] = true; 
                }
            }
        }
        
        // Stores nodes at distance k from the target
        vector<int> result; 
        while (!queue.empty()) { 
            // Extract nodes at distance k from the queue
            TreeNode* current = queue.front();
            queue.pop();
            // Store node values in the result vector
            result.push_back(current->val); 
        }

        
        // Return nodes at distance
        // K from the target
        return result; 
    }
};

// Main function
int main() {
    // Create a sample tree for testing
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;
    TreeNode* target = root->left;
    int k = 2;
    // Find nodes at distance 2 from the target node
    vector<int> result = sol.distanceK(root, target, k); 

    // Print the elements at distance k from the target node
    cout << "Nodes at distance " << k << " from target node " << target->val << ": ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}