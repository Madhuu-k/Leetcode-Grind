// Problem Link: https://leetcode.com/problems/subsets/?envType=problem-list-v2&envId=array
// Time Complexity: O(2^n × n)

class Solution {
public:
    void generateSubsets(vector<int>& arr, vector<int>& current, vector<vector<int>>& result, int index){
        if(index == arr.size()){
            result.push_back(current);
            return;
        }
        current.push_back(arr[index]);
        generateSubsets(arr, current, result, index + 1);

        current.pop_back();
        generateSubsets(arr, current, result, index + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> result;
        generateSubsets(nums, current, result, 0);
        return result;
    }
};