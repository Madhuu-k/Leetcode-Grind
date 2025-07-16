// Problem Link: https://leetcode.com/problems/group-anagrams/?envType=problem-list-v2&envId=string
// Time Complexity: O(N * K log K)


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(string s : strs){
            string key = s;
            sort(key.begin(), key.end()); // sort and take each as key value pair
            map[key].push_back(s); // Add the original string to map
        }
        vector<vector<string>> res;
        for(auto& pair : map) res.push_back(pair.second);
        return res;
    }
};