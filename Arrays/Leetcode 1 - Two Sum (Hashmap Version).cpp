// Problem Link: https://leetcode.com/problems/two-sum/
// Time Complexity: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i =0; i < nums.size(); i++){
            int need = target - nums[i];
            if(mp.count(need)) return {mp[need], i};
            mp[nums[i]] = i;
        }
        return {};
    }
};