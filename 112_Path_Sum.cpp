class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        // if node does not exist
        if (!root) {
            return false;
        }

        // if leaf node reached
        if (!root->left && !root->right) {

            // check if this leaf completes remaining target
            return targetSum == root->val;
        }

        // subtract current node value
        int remaining = targetSum - root->val;

        // try left path OR right path
        return hasPathSum(root->left, remaining) ||
               hasPathSum(root->right, remaining);
    }
};