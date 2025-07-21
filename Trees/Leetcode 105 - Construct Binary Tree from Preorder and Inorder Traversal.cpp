// Problem Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Time Complexity: o(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> inorderMap;
    int preorderIndex = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) inorderMap[inorder[i]] = i;
        return build(preorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, int inStart, int inEnd){
        if(inStart > inEnd) return nullptr;
        int rootval = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootval);
        int inIndex = inorderMap[rootval];

        root -> left = build(preorder, inStart, inIndex - 1);
        root -> right = build(preorder, inIndex + 1, inEnd);
        return root;
    }
};