// Problem Link: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers
// Time Complexity: O(nlogn)

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size() % k != 0) return false;
        sort(nums.begin(), nums.end());

        unordered_map<int, int> freq;
        for(int x : nums) freq[x]++;

        for(int x : nums){
            if(freq[x] == 0) continue;
            for(int i = 0; i < k; i++){
                int curr = x + i;
                if(freq[curr] == 0) return false;
                freq[curr]--;
            }
        }

        return true;
    }
};