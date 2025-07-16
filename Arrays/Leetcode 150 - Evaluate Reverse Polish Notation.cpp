// Problem Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/?envType=problem-list-v2&envId=array
// Time Complexity: O(n)

class Solution {
public:
    int evalRPN(vector<string>& exp) {
        stack<int> st;
        for(string ch : exp){
            if(ch == "+" || ch == "-" || ch == "*" || ch == "/") {
                int val2 = st.top(); st.pop();
                int val1 = st.top(); st.pop();

                if(ch == "+") st.push(val1 + val2);
                else if(ch == "-") st.push(val1 - val2);
                else if(ch == "*") st.push(val1* val2);
                else if(ch == "/") st.push(val1 / val2);
            }
            else{
                st.push(stoi(ch));
            }
        }
        return st.top();
    }
};