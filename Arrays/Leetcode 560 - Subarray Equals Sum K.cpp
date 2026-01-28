// Problem Link: https://leetcode.com/problems/subarray-sum-equals-k/
// Time Complexity: O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int sum = 0, count = 0;
        freq[0] = 1;
        for(int x : nums){
            sum += x;
            if(freq.count(sum - k)) count += freq[sum - k];
            freq[sum]++;
        }
        return count;
    }
};