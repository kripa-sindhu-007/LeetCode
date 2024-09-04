/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (!root)
            return {};
        queue<Node*> q;
        q.push(root);
        Node* curr = NULL;
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                curr = q.front();
                q.pop();
                level.push_back(curr->val);
                if (curr->children.size() != 0) {
                    for (auto it : curr->children)
                        q.push(it);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};