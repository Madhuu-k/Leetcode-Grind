// Problem Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/
// Time Complexity: O(n)

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefixSum = 0, count = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        for(int num : nums){
            prefixSum += num;
            int mod = prefixSum % k;
            if(mod < 0) mod += k;
            if(map.count(mod)) count += map[mod];
            map[mod]++;
        }
        return count;
    }
};