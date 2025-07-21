// Problem Link: https://leetcode.com/problems/search-in-a-binary-search-tree/submissions/1700802669/
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
    TreeNode* insertIntoBST(TreeNode* root, int key) {
        if(root == nullptr) return new TreeNode(key);
        if(key < root -> val) root -> left = insertIntoBST(root -> left, key);
        else if(key > root -> val) root -> right = insertIntoBST(root -> right, key);
        return root;
    }
};