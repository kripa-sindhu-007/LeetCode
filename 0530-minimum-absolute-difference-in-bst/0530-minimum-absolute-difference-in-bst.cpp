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
    int minDiff = INT_MAX;
    TreeNode* prev = nullptr;
    void inorder(TreeNode* root) {
        if (!root)
            return;

        inorder(root->left);

        if (prev) {
            minDiff = min(minDiff, abs(prev->val - root->val));
        }
        prev = root;
        inorder(root->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
};