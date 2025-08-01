// Problem Link: https://leetcode.com/problems/boats-to-save-people/
// Time Complexity: o(n log n)

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1, boats = 0;
        while(i <= j){
            if(people[i] + people[j] <= limit) i++;
            j--; boats++;
        }
        return boats;
    }
};