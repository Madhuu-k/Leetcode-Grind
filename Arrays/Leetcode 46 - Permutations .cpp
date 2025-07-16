// Problem Link: https://leetcode.com/problems/permutations/?envType=problem-list-v2&envId=array
// Time Complexity: O(n × n!)

class Solution {
public:
    void permuteCombinations(vector<int>& arr, vector<vector<int>>& result, int index){
        if(index == arr.size()){
            result.push_back(arr);
            return;
        }

        for(int i = index; i < arr.size(); i++){
            swap(arr[index], arr[i]);
            permuteCombinations(arr, result, index + 1);
            swap(arr[index], arr[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permuteCombinations(nums, result, 0);
        return result;
    }
};