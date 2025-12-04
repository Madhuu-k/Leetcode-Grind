// Problem Link: https://leetcode.com/problems/fruit-into-baskets/
// Time Complexity: O(n)

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, best = 0;
        unordered_map<int, int>mp;

        for(int right = 0; right < fruits.size(); right++){
            mp[fruits[right]]++;

            if(mp.size() > 2){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0) mp.erase(fruits[left]);
                left++;
            }

            best = max(best, right - left + 1);
        }
        return best;
    }
};