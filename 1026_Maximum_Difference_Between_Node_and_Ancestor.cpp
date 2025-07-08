// Leetcode 1026 - Maximum Difference Between Node and Ancestor
// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

class Solution {
    public:
        // Helper DFS function to traverse tree with current min and max values
        int dfs(TreeNode* node, int minv, int maxv) {
            if (!node) return maxv - minv;  // Return max difference at leaf
    
            // Update min and max with current node's value
            minv = min(minv, node->val);
            maxv = max(maxv, node->val);
    
            // Recursively compute for left and right subtrees
            int left = dfs(node->left, minv, maxv);
            int right = dfs(node->right, minv, maxv);
    
            // Return the max diff from both subtrees
            return max(left, right);
        }
    
        int maxAncestorDiff(TreeNode* root) {
            // Start DFS with root's value as initial min and max
            return dfs(root, root->val, root->val);
        }
    };
    