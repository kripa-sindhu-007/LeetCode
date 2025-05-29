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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> avgLevel;
        if (!root)
            return avgLevel;

        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* curr_node = q.front();
                sum += curr_node->val;
                if (curr_node->left)
                    q.push(curr_node->left);
                if (curr_node->right)
                    q.push(curr_node->right);
                q.pop();
            }
            double avg = sum / size;
            avgLevel.push_back(avg);
        }
        return avgLevel;
    }
};