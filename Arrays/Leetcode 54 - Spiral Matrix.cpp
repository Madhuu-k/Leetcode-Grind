// Problem Link: https://leetcode.com/problems/spiral-matrix/
// Time Complexity: O(m.n)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int left = 0, right = matrix[0].size() - 1;
        int top = 0, bottom = matrix.size() - 1;

        while(top <= bottom && left <= right){
            //1. left to right
            for(int j = left; j <= right; j++) res.push_back(matrix[top][j]);
            top++;

            // 2. top to bottom
            for(int i = top; i <= bottom; i++) res.push_back(matrix[i][right]);
            right--;

            // 3. right to left
            if(top <= bottom){
                for(int j = right; j >= left; j--) res.push_back(matrix[bottom][j]);
                bottom--;
            }

            // 4. bottom to top
            if(left <= right){
                for(int i = bottom; i >= top; i--) res.push_back(matrix[i][left]);
                left++;
            }
        }
        return res;
    }
};