// Leetcode 1026 - Maximum Difference Between Node and Ancestor
// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

class Solution {
    public int maxAncestorDiff(TreeNode root) {
        // Start DFS with root value as both min and max
        return dfs(root, root.val, root.val);
    }

    // Helper function to traverse tree while tracking min and max ancestor values
    private int dfs(TreeNode node, int minv, int maxv) {
        if (node == null) {
            // When we reach leaf, return the max diff
            return maxv - minv;
        }

        // Update min and max values along the path
        minv = Math.min(minv, node.val);
        maxv = Math.max(maxv, node.val);

        // Recursively call for left and right subtrees
        int left = dfs(node.left, minv, maxv);
        int right = dfs(node.right, minv, maxv);

        // Return the greater of two
        return Math.max(left, right);
    }
}
