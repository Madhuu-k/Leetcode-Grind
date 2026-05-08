// Problem Link: https://leetcode.com/problems/hand-of-straights/description/
// Time Complexity: O(nlogn)

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        sort(hand.begin(), hand.end());

        unordered_map<int, int> freq;
        for(int x : hand) freq[x]++;

        for(int x : hand){
            if(freq[x] == 0) continue;

            for(int i = 0; i < groupSize; i++){
                int currElement = x + i;
                if(freq[currElement] == 0) return false;
                freq[currElement]--;
            }
        }

        return true;
    }
};
