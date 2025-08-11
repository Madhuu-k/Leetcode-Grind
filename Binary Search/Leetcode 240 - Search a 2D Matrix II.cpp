// Problem Link: https://leetcode.com/problems/search-a-2d-matrix-ii/
// Time Complexity: o(m + n)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = n - 1;
        while(row < m && col >= 0){
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) col--;
            else row++;
        }
        return false;
    }
};