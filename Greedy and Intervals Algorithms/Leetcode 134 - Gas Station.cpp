// Problem Link: https://leetcode.com/problems/gas-station/
// Time Complexity: o(n)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0, currCap = 0, startPos = 0;
        for(int i = 0; i < gas.size(); i++){
            int gain = gas[i] - cost[i];
            tank += gain;
            currCap += gain;

            if(currCap < 0){
                startPos = i + 1;
                currCap = 0;
            }
        }
        return tank >= 0 ? startPos : -1;
    }
};