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
private:
    int helper(TreeNode* root, int& depth) {
        if (!root)
            return 0;
        int leftMax = helper(root->left, depth);
        int rightMax = helper(root->right, depth);
        return depth = max(leftMax, rightMax) + 1;
    }

public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        helper(root, depth);
        return depth;
    }
};