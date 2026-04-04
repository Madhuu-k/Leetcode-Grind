// Problem Link: https://leetcode.com/problems/minimum-absolute-difference/
// Time Complexity: O(n)

class Solution {
public:
    vector<vector<int> > minimumAbsDifference(vector<int> &arr) {
        vector<vector<int> > res;
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        for (int i = 1; i < arr.size(); i++) {
            int diff = abs(arr[i] - arr[i - 1]);

            if (diff < minDiff) {
                res.clear();
                res.push_back({arr[i - 1], arr[i]});
                minDiff = diff;
            } else if (diff == minDiff) {
                res.push_back({arr[i - 1], arr[i]});
            }
        }
        return res;
    }
};
