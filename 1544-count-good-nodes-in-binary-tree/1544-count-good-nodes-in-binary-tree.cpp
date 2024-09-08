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
    // int count = 0;

private:
    int helper(TreeNode* root, int max_allowed) {
        if (!root)
            return 0;
        int count = 0;
        if (root->val >= max_allowed)
            count = 1;

        max_allowed = max(max_allowed, root->val);
        // if (root->left)
        count += helper(root->left, max_allowed);
        // if (root->right)
        count += helper(root->right, max_allowed);

        return count;
    }

public:
    int goodNodes(TreeNode* root) {
        int max_allowed = INT_MIN;
        // int count=0;
        return helper(root, max_allowed);
        // return count;
    }
};