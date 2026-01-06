// Problem Link: https://leetcode.com/problems/rotate-string/
// Time Complexity: O(n^2)

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        string temp = s + s;
        if(temp.find(goal) != string::npos) return true;
        else return false;
    }
};