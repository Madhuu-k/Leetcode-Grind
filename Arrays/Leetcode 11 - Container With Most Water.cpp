// Problem Link: https://leetcode.com/problems/container-with-most-water/
// Time Complexity: o(n)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxAr = 0;
        while(left < right){
            int h = min(height[left], height[right]);
            int w = right - left;
            maxAr = max(maxAr, h * w);

            if(height[left] < height[right]) left++;
            else right--;
        }
        return maxAr;
    }
};