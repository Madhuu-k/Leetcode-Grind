// Problem Link: https://leetcode.com/problems/majority-element/?envType=problem-list-v2&envId=array
// Time Complexity: O(n)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int majority = nums.size() / 2;

        for (int num : nums) {
            counts[num]++;
            if (counts[num] > majority) {
                return num;
            }
        }

        return -1; // Technically unreachable if a majority always exists
    }
};
