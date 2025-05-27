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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> all_level;
        bool left_flag = true;
        if (!root)
            return all_level;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> curr_level(size);
            for (int i = 0; i < size; i++) {
                TreeNode* curr_node = q.front();
                int idx;
                if (left_flag)
                    idx = i;
                else
                    idx = size - i - 1;
                curr_level[idx] = curr_node->val;
                q.pop();

                if (curr_node->left)
                    q.push(curr_node->left);
                if (curr_node->right)
                    q.push(curr_node->right);
            }
            all_level.push_back(curr_level);
            left_flag = !left_flag;
        }
        return all_level;
    }
};