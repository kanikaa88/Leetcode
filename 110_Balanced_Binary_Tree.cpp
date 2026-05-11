/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxdepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftmax = maxdepth(root->left);
        int rightmax = maxdepth(root->right);
        return 1 + max(leftmax, rightmax);
    }
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        int lefty = maxdepth(root->left);
        int righty = maxdepth(root->right);
        return abs(lefty - righty) <= 1 && isBalanced(root->left) &&
               isBalanced(root->right);
    }
};