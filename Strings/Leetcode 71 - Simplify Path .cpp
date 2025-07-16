// Problem Link: https://leetcode.com/problems/simplify-path/?envType=problem-list-v2&envId=string
// Time Complexity: o(n)

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string res, temp;
        stringstream ss(path);

        while(getline(ss, temp, '/')){
            if(temp == "" || temp == ".") continue;
            else if(temp == ".."){
                if(!st.empty()) st.pop();
            }
            else st.push(temp);
        }

        while(!st.empty()){
            res = "/" + st.top() + res;
            st.pop();
        }

        return res.empty() ? "/" : res;
    }
};