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
private:
    void traversal(Node* root, vector<int>& ans) {
        if (!root)
            return;
        for (auto& it : root->children) {
            traversal(it, ans);
        }
        ans.push_back(root->val);
    }

public:
    vector<int> postorder(Node* root) {
        vector<int> post_traversal;
        traversal(root, post_traversal);
        return post_traversal;
    }
};