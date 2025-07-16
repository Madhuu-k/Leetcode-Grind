// Problem Link: https://leetcode.com/problems/valid-parentheses/?envType=problem-list-v2&envId=string
// Time Complexity: o(n)

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(char ch : s){
            if(ch == '(' || ch == '[' || ch == '{') st.push(ch);
            else{
                if(st.empty()) return false;
                char stackTop = st.top();

                if(ch == ')' && stackTop == '(' ||
                ch == ']' && stackTop == '[' || ch == '}' && stackTop == '{'
                ) st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};