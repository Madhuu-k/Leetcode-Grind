// Problem Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
// Time Complexity: O(n)

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> level;
            int levelSize = q.size();

            for(int i = 0; i < levelSize; i++){
                TreeNode* node = q.front(); q.pop();
                level.push_back(node -> val);

                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
            result.push_back(level);
        }
        return result;
    }
};

