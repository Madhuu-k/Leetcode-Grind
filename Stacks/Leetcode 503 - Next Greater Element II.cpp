// Problem Link: https://leetcode.com/problems/next-greater-element-ii/
// Time Complexity: O(n)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i = n*2 - 1; i >= 0; i--){
            int curr = nums[i % n];
            while(!st.empty() && st.top() <= curr) st.pop();
            if(i < n) ans[i] = st.empty() ? -1 : st.top();
            st.push(curr);
        }

        return ans;
    }
};