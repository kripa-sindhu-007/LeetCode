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
    int kth;
    void helper(TreeNode* root, int k, priority_queue<int>& pq) {
        if (!root)
            return;

        if (root->left)
            helper(root->left, k, pq);
        pq.push(root->val);
        if (root->right)
            helper(root->right, k, pq);

        if (pq.size() > k)
            pq.pop();
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;
        helper(root, k, pq);
        int ans = pq.top();
        return ans;
    }
};