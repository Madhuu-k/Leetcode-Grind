// Problem Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToright = true;
        while(!q.empty()){
            int levelSize = q.size();
            vector<int> level(levelSize);

            for(int i = 0; i < levelSize; i++){
                TreeNode* node = q.front(); q.pop();
                int index = leftToright? i : (levelSize - i - 1);
                level[index] = node -> val;
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
            result.push_back(level);
            leftToright = !leftToright;
        }
        return result;
    }
};