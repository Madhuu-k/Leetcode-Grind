// Problem Link: https://leetcode.com/problems/sqrtx/
// Time Complexity: O(log n)

class Solution {
public:
    int mySqrt(int x) {
        long long int left = 1, right = x, ans = 0;
        while(left <= right){
            long long int mid = left + (right - left) / 2;
            if(x == (mid * mid)) return mid;
            else if((mid * mid) < x){
                ans = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return ans;
    }
};