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
    priority_queue<int> pq;
    void helper(TreeNode* root, int k) {
        if (!root)
            return;
        pq.push(root->val);
        if (root->left)
            helper(root->left, k);
        if (root->right)
            helper(root->right, k);
        if (pq.size() > k)
            pq.pop();
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        helper(root, k);
        return pq.top();
    }
};