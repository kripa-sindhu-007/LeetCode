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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> idxInorder;
        for (int i = 0; i < inorder.size(); i++) {
            idxInorder[inorder[i]] = i;
        }
        int postStart = 0;
        int postEnd = postorder.size() - 1;
        int inStart = 0;
        int inEnd = inorder.size() - 1;

        return helper(inorder, inStart, inEnd, postorder, postStart, postEnd,
                      idxInorder);
    }

private:
    TreeNode* helper(vector<int>& inorder, int inStart, int inEnd,
                     vector<int>& postorder, int postStart, int postEnd,
                     unordered_map<int, int>& idxInorder) {
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }
        int currNode = postorder[postEnd];
        TreeNode* root = new TreeNode(currNode);
        int inorderIdx = idxInorder[currNode];
        int noOfLeftNodes = inorderIdx - inStart;

        root->left =
            helper(inorder, inStart, inorderIdx - 1, postorder, postStart,
                   postStart + noOfLeftNodes - 1, idxInorder);

        root->right =
            helper(inorder, inorderIdx + 1, inEnd, postorder,
                   postStart + noOfLeftNodes, postEnd - 1, idxInorder);

        return root;
    }
};