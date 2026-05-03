// Problem Link: https://leetcode.com/problems/can-place-flowers/
// Time Complexity: o(n)

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        for(int i = 0; i < size && n > 0; i++){
            if(flowerbed[i] == 0){
                bool left = (i == 0) || (flowerbed[i - 1] == 0);
                bool right = (i == size - 1) || (flowerbed[i + 1] == 0);
                if(left && right){
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        return n == 0;
    }
};