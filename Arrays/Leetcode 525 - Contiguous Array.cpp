// Problem Link: https://leetcode.com/problems/contiguous-array/
// Time Complexity: O(n)

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> firstIndex;
        int sum = 0, ans = 0;
        firstIndex[0] = -1; // base case

        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 1 ? 1 : -1);

            if (firstIndex.count(sum)) {
                ans = max(ans, i - firstIndex[sum]);
            } else {
                firstIndex[sum] = i;
            }
        }
        return ans;
    }
};
