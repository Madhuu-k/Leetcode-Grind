// Problem Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    int postIndex;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size() - 1;
        for(int i = 0; i < inorder.size(); i++) inorderMap[inorder[i]] = i;
        return build(postorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& postorder, int inStart, int inEnd){
        if(inStart > inEnd) return nullptr;
        int rootval = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootval);
        int inIndex = inorderMap[rootval];

        root -> right = build(postorder, inIndex + 1, inEnd);
        root -> left = build(postorder, inStart, inIndex - 1);

        return root;
    }
};