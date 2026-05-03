// Problem Link: https://leetcode.com/problems/merge-intervals
// Time Complexity: O(nlogn)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());

        for(auto it : intervals){
            if(res.empty()) res.push_back(it);

            vector<int> last = res.back();
            if(it[0] <= last[1]){
                res.back()[1] = max(res.back()[1], it[1]);
            }

            else res.push_back(it);
        }

        return res;
    }
};