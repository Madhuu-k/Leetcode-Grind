// Problem Link: https://leetcode.com/problems/continuous-subarray-sum/
// Time Complexity: O(n)

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefixSum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;

        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];
            int mod = prefixSum % k;
            if(mp.count(mod)){
                if(i - mp[mod] > 1) return true; // return true if length is more than or equal to 2
            }
            else mp[mod] = i;
        }
        return false;
    }
};