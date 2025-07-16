// Problem Link: https://leetcode.com/problems/balanced-binary-tree/description
// Time Complexity: o(n)

class Solution {
public:
    int checkHeight(TreeNode* root){
        if(root == nullptr) return 0;
        int left =  checkHeight(root -> left);
        if(left == -1) return -1;

        int right = checkHeight(root -> right);
        if(right == -1) return -1;

        if(abs(left - right) > 1) return -1;
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        return checkHeight(root) != -1;
    }
};