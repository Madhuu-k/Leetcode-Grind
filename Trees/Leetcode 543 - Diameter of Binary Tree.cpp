// Problem Link: https://leetcode.com/problems/diameter-of-binary-tree/submissions/1698236352/
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
    int maxDia = 0;
    int height(TreeNode* root){
        if(root == nullptr) return 0;
        int left = height(root -> left);
        int right = height(root -> right);

        maxDia = max(maxDia, left + right);
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxDia;
    }
};