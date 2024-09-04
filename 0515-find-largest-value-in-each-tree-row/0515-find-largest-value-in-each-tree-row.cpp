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
    vector<int> largestValues(TreeNode* root) {
        vector<int> maxval;
        if (!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* curr = NULL;
        while (!q.empty()) {
            int size = q.size();
            int row_max = INT_MIN;
            for (int i = 0; i < size; i++) {
                curr = q.front();
                row_max = max(row_max, curr->val);
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            maxval.push_back(row_max);
        }
        return maxval;
    }
};