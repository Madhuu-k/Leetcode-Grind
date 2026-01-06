// Problem Link: https://leetcode.com/problems/check-if-the-sentence-is-pangram/
// Time Complexity: O(n)

class Solution {
public:
    bool checkIfPangram(string s) {
        vector<bool> seen(26, false);
        for(char c : s){
            if(isalpha(c)){
                c = tolower(c);
                seen[c - 'a'] = true;
            }
        }

        for(bool present : seen){
            if(!present) return false;
        }

        return true;
    }
};