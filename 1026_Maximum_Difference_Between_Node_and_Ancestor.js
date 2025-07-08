// Leetcode 1026 - Maximum Difference Between Node and Ancestor
// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

/**
 * Definition for a binary tree node:
 * function TreeNode(val, left, right) {
 *     this.val = (val === undefined ? 0 : val);
 *     this.left = (left === undefined ? null : left);
 *     this.right = (right === undefined ? null : right);
 */

/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxAncestorDiff = function(root) {
    // Recursive DFS function that tracks min/max along the current path
    const dfs = (node, minv, maxv) => {
        if (!node) {
            // Return the max difference between ancestor and node
            return maxv - minv;
        }

        // Update current min and max with node value
        minv = Math.min(minv, node.val);
        maxv = Math.max(maxv, node.val);

        // Explore both subtrees
        const left = dfs(node.left, minv, maxv);
        const right = dfs(node.right, minv, maxv);

        // Return the max difference found
        return Math.max(left, right);
    };

    return dfs(root, root.val, root.val);
};
