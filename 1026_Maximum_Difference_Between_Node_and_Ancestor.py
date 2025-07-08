# Leetcode 1026 - Maximum Difference Between Node and Ancestor
# https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

# The idea: At each node, track the minimum and maximum values from root to that node.
# The difference between max and min gives the max ancestor difference at that path.

class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        # Recursive DFS function
        def dfs(node, minv, maxv):
            if not node:
                # Return max difference when we reach a leaf
                return maxv - minv

            # Update min and max with the current node's value
            minv = min(minv, node.val)
            maxv = max(maxv, node.val)

            # Recur for left and right subtrees
            left = dfs(node.left, minv, maxv)
            right = dfs(node.right, minv, maxv)

            # Return the max diff found from both sides
            return max(left, right)

        # Start DFS from root, using its value as initial min and max
        return dfs(root, root.val, root.val)
