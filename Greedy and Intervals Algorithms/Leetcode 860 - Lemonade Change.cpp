// Problem Link: https://leetcode.com/problems/lemonade-change/
// Time Complexity: o(n)

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(int bill : bills){
            if(bill == 5) five++;
            else if(bill == 10){
                if(five == 0) return false;
                ten++; five--;
            }
            else{
                if(ten > 0 && five > 0){
                    ten--;
                    five--;
                }
                else if(five >= 3) five -= 3;
                else return false;
            }
        }
        return true;
    }
};