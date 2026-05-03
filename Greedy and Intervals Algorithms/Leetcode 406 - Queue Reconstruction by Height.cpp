// Problem Link: https://leetcode.com/problems/queue-reconstruction-by-height/
// Time Complexity: o(n log n)

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });
        vector<vector<int>> heights;
        for(auto& p : people){
            heights.insert(heights.begin() + p[1], p);
        }
        return heights;
    }
};