// Problem Link: https://leetcode.com/problems/generate-parentheses/description/
// Time Complexity: O(4^n / sqrt(n))

class Solution {
public:
    void generateParen(int open, int close, int n, vector<string>& ans, string& curr){
        if(curr.length() == n * 2 ){
            ans.push_back(curr);
            return;
        }

        if(open < n){
            curr.push_back('(');
            generateParen(open + 1, close, n, ans, curr);
            curr.pop_back();
        }

        if(close < open){
            curr.push_back(')');
            generateParen(open, close + 1, n, ans, curr);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string res = "";
        vector<string> ans;
        generateParen(0, 0, n, ans, res);
        return ans;
    }
};