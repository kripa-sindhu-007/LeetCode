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
    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd,
                     vector<int>& inorder, int inStart, int inEnd,
                     unordered_map<int, int>& inorderMap) {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        int rootNode = preorder[preStart];
        TreeNode* root = new TreeNode(rootNode);

        int rootInInorder = inorderMap[rootNode];
        int noOfLeftNode = rootInInorder - inStart;

        root->left = helper(preorder, preStart + 1, preStart + noOfLeftNode,
                            inorder, inStart, rootInInorder - 1, inorderMap);
        root->right = helper(preorder, preStart + noOfLeftNode + 1, preEnd,
                             inorder, rootInInorder + 1, inEnd, inorderMap);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return nullptr;
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        int preStart = 0;
        int preEnd = preorder.size() - 1;
        int inStart = 0;
        int inEnd = inorder.size() - 1;
        return helper(preorder, preStart, preEnd, inorder, inStart, inEnd,
                      inorderMap);
    }
};