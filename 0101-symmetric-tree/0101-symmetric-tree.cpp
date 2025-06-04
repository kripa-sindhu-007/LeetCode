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
    bool SymmetricTest(TreeNode* leftHalf, TreeNode* rightHalf) {
        if (!leftHalf && !rightHalf)
            return true;
        if (!leftHalf || !rightHalf)
            return false;
        if (leftHalf->val != rightHalf->val)
            return false;
        return SymmetricTest(leftHalf->left, rightHalf->right) &&
               SymmetricTest(leftHalf->right, rightHalf->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return SymmetricTest(root->left, root->right);
    }
};