// Problem Link: https://leetcode.com/problems/contains-duplicate/description/?envType=problem-list-v2&envId=array
// Time Complexity: O(n)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }

        return false;
    }
};
