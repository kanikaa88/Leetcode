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
    int diameter = 0;
    int heights(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftheight = heights(root->left);
        int rightheight = heights(root->right);
        diameter = max(diameter, leftheight + rightheight);
        return 1 + max(leftheight, rightheight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        heights(root);
        return diameter;
    }
};