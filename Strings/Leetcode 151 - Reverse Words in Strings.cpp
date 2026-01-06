// Problem Link: https://leetcode.com/problems/reverse-words-in-a-string/description/
// Time Complexity: O(n)

class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int i = s.length() - 1;

        while(i >= 0){
            while(i >= 0 && s[i] == ' ') i--;

            if(i < 0) break;

            string word = "";

            while(i >= 0 && s[i] != ' '){
                word = s[i] + word;
                i--;
            }

            if(result.length() == 0) result = word;
            else result = result + ' ' + word ;
        }
        return result;
    }
};