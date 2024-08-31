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
    vector<int> traverse(TreeNode* root) {
        if (!root)
            return {0, 0};

        vector<int> leftsub = traverse(root->left);
        vector<int> rightsub = traverse(root->right);

        int withroot = root->val + leftsub[1] + rightsub[1];
        int withoutroot =
            max(leftsub[0], leftsub[1]) + max(rightsub[0], rightsub[1]);
        return {withroot, withoutroot};
    }

public:
    int rob(TreeNode* root) {
        vector<int> res = traverse(root);
        return max(res[0], res[1]);
    }
};