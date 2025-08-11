// Problem Link: https://leetcode.com/problems/search-a-2d-matrix/
// Time Complexity: o(log(m * n))

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while(left <= right){
            int mid = left  + (right - left) / 2;
            int row = mid / n; int col = mid % n;
            int midVal = matrix[row][col];
            if(midVal == target) return true;
            if(midVal < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};