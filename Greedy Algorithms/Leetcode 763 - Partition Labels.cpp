// Problem Link: https://leetcode.com/problems/partition-labels/
// Time Complexity: o(n)

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26);
        for(int i = 0; i < s.size(); i++) last[s[i] - 'a'] = i;
        int start = 0, end = 0;
        vector<int> result;
        for(int i = 0; i < s.size(); i++){
            end = max(end, last[s[i] - 'a']);
            if(i == end){
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};