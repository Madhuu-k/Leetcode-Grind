// Problem Link: https://leetcode.com/problems/recover-binary-search-tree/
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
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(first && last) swap(first -> val, last -> val);
        else if(first && middle) swap(first -> val, middle -> val);
    }

    TreeNode* first = NULL;
    TreeNode* last = NULL;
    TreeNode* middle = NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root -> left);
        if(prev && root -> val < prev -> val){
            if(!first){
                first = prev;
                middle = root;
            }
            else last = root;
        }
        prev = root;
        inorder(root -> right);
    }

};