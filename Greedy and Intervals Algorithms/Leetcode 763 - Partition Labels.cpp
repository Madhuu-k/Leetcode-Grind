// Problem Link: https://leetcode.com/problems/partition-labels/
// Time Complexity: o(n)

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastPosition(26);
        for(int i = 0; i < s.length(); i++) lastPosition[s[i] - 'a'] = i;

        // Partitions
        int start = 0, end = 0;
        vector<int> res;
        for(int i = 0; i < s.length(); i++){
            end = max(end, lastPosition[s[i] - 'a']);
            if(i == end){
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return res;
    }
};