// Problem Link: https://leetcode.com/problems/permutations-ii/?envType=problem-list-v2&envId=array
// Time Complexity: O(n log n) or O(n x n!)

class Solution {
public:
    void permuteDuplicates(vector<int>& arr, vector<int>& current, vector<vector<int>>& result,      vector<bool>& used){
        if(current.size() == arr.size()){
            result.push_back(current);
            return;
        }

        for(int i = 0; i < arr.size(); i++){
            if(used[i]) continue;

            if(i > 0 && arr[i] == arr[i - 1] && !used[i - 1]) continue;
            used[i] = true;
            current.push_back(arr[i]);
            permuteDuplicates(arr, current, result, used);

            used[i] = false;
            current.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        vector<int> current;
        permuteDuplicates(nums, current, result, used);
        return result;
    }
};