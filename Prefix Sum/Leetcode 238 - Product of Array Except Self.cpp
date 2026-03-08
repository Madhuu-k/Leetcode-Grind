// Problem Link: https://leetcode.com/problems/product-of-array-except-self/
// Time Complexity: O(n)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);

        int preix = 1;
        for(int i = 0; i < nums.size(); i++){
            ans[i] = preix;
            preix *= nums[i];
        }

        int sufix = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            ans[i] *= sufix;
            sufix *= nums[i];
        }

        return ans;
    }
};