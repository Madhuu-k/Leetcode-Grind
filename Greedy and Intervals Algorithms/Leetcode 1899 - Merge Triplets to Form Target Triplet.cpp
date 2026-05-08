// Problem Link: https://leetcode.com/problems/merge-triplets-to-form-target-triplet/
// Time Complexity: O(n)

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> ans(3, 0);

        for(auto& it : triplets){
            if(it[0] > target[0] ||
               it[1] > target[1] ||
               it[2] > target[2]) continue;

            ans[0] = max(ans[0], it[0]);
            ans[1] = max(ans[1], it[1]);
            ans[2] = max(ans[2], it[2]);
        }

        return ans == target;
    }
};
