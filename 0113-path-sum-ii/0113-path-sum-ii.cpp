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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(root, targetSum, ans, curr);
        return ans;
    }

private:
    void helper(TreeNode* root, int targetSum, vector<vector<int>>& ans,
                vector<int>& curr) {

        if (!root)
            return;

        curr.push_back(root->val); // choose
        if (!root->left && !root->right && targetSum == root->val) {
            ans.push_back(curr);
        } else {
            helper(root->left, targetSum - root->val, ans, curr); // explore
            helper(root->right, targetSum - root->val, ans, curr);
        }

        curr.pop_back(); // backtrack
    }
};