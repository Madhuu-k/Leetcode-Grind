// Problem Link: https://leetcode.com/problems/single-number/?envType=problem-list-v2&envId=array
// Time Complexity: O(n)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        unordered_map<int, int> freq;

        for(int num : nums) freq[num]++;

        int minFreq = INT_MAX;
        int minElement = -1;

        for(auto it : freq){
            if(it.second < minFreq){
                minFreq = it.second;
                minElement = it.first;
            }
        }
        return minElement;
    }
};