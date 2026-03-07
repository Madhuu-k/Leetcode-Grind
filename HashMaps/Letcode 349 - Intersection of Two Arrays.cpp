// Problem Link: https://leetcode.com/problems/intersection-of-two-arrays/
// Time Complexity: O(n)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        unordered_set<int> result;

        for(int x : nums2){
            if(s.count(x)) result.insert(x);
        }

        return vector<int>(result.begin(), result.end());
    }
};