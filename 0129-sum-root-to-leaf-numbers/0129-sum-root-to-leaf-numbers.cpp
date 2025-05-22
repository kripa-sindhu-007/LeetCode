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
    void dfs(TreeNode* root, int curr_sum, int& total_sum) {
        if (!root)
            return;

        curr_sum = curr_sum * 10 + root->val;

        if (!root->left && !root->right) {
            total_sum += curr_sum;
            return;
        }
        dfs(root->left, curr_sum, total_sum);
        dfs(root->right, curr_sum, total_sum);
    }

public:
    int sumNumbers(TreeNode* root) {
        int total_sum = 0;
        int curr_sum = 0;
        dfs(root, curr_sum, total_sum);
        return total_sum;
    }
};