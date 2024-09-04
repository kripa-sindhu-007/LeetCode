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
    int goodNodes(TreeNode* root) {
        // if (!root)
        //     return 0;
        // queue<pair<TreeNode*, int>> q;
        // q.push({root, root->val});
        // int goodNode = 0;
        // while (!q.empty()) {
        //     auto [node, max_val] = q.front();
        //     q.pop();

        //     if (max_val <= node->val)
        //         goodNode++;

        //     max_val = max(max_val, node->val);

        //     if (node->left)
        //         q.push({node->left, max_val});
        //     if (node->right)
        //         q.push({node->right, max_val});
        // }
        // return goodNode;

        return dfs(root, INT_MIN);
    }

private:
    int dfs(TreeNode* node, int curr_max) {
        if (!node)
            return 0;

        int good = 0;

        if (node->val >= curr_max)
            good = 1;

        curr_max = max(curr_max, node->val);

        good += dfs(node->left, curr_max);
        good += dfs(node->right, curr_max);

        return good;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();