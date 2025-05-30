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
    bool helper(TreeNode* root, long long min, long long max) {
        if (!root)
            return true;

        if (root->val <= min || root->val >= max)
            return false;

        return helper(root->left, min, root->val) &&
               helper(root->right, root->val, max);
    }

public:
    bool isValidBST(TreeNode* root) {
        long long max = LONG_LONG_MAX;
        long long min = LONG_LONG_MIN;
        return helper(root, min, max);
    }
};