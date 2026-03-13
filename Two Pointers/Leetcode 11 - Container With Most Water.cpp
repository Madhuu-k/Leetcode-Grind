// Problem Link: https://leetcode.com/problems/container-with-most-water/
// Time Complexity: O(n)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxVol = 0;
        while(left < right){
            int h = min(height[left], height[right]);
            int w = right - left;
            int vol = h * w;

            maxVol = max(maxVol, vol);
            if(height[left] < height[right]) left++;
            else right--;
        }
        return maxVol;
    }
};
