// Problem Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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
    int i = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder);
    }

    TreeNode* build(vector<int>& preorder, int bound = INT_MAX){
        if(i == preorder.size() || preorder[i] > bound) return nullptr;
        TreeNode* root = new TreeNode(preorder[i++]);
        root -> left = build(preorder, root -> val);
        root -> right = build(preorder, bound);
        return root;
    }
};