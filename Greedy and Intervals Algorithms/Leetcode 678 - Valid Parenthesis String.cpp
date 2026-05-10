// Problem Link: https://leetcode.com/problems/valid-parenthesis-string/description/
// Time Complexity: O(n)

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for(char c : s){
            if(c == '('){
                low++; high++;
            }
            else if(c == ')'){
                low--; high--;
            }
            else{
                low--;
                high++;
            }
            if(high < 0) return false; // Too many closing brackets
            low = max(low, 0); // Low can go below 0 when there are many *
        }
        return low == 0;
    }
};
