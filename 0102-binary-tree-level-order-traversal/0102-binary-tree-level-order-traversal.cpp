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
    void traversal(TreeNode* root, vector<vector<int>>& ans) {
        if (!root)
            return;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            vector<int> levelNode;
            for (int i = 1; i <= size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                levelNode.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }

            ans.push_back(levelNode);
        }
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        traversal(root, ans);
        return ans;
    }
};