// Problem Link: https://leetcode.com/problems/search-a-2d-matrix/
// Time Complexity: o(m. log n)

class Solution {
public:
    bool isThere(vector<int>& arr, int target){
        int left = 0, right = arr.size() - 1;
        bool res = false;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(arr[mid] == target) return true;
            else if(arr[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto it : matrix){
            if(isThere(it, target)) return true;
        }
        return false;
    }
};
