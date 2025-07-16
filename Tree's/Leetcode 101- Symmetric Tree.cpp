// Problem Link: https://leetcode.com/problems/balanced-binary-tree/
// Time Complexity: o(n)

class Solution {
public:
    bool isMirror(TreeNode* t1, TreeNode* t2){
        if(t1 == nullptr && t2 == nullptr) return true;
        if(t1 == nullptr || t2 == nullptr) return false;

        return(t1 -> val == t2 -> val) && isMirror(t1 -> left, t2 -> right) &&
        isMirror(t1 -> right, t2 -> left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return isMirror(root -> left, root -> right);
    }
};