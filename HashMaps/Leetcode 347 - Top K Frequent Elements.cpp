// Problem Link:
// Time Complexity: O(n log n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int x : nums) freq[x]++;

        vector<pair<int, int>> pairs;
        for(auto it : freq) pairs.push_back({it.second, it.first});

        sort(pairs.begin(), pairs.end(), greater<>());

        vector<int> result;

        for(int i = 0; i < k; i++){
            result.push_back(pairs[i].second);
        }

        return result;
    }
};
