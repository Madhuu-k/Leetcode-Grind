// Problem Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Time Complexity: O(log n)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 2;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] > arr[mid + 1]) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};