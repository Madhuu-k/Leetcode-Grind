// Problem Link: https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
// Time Complexity: O(n)

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int  count = 0, left = 0;
        long long sum = 0, need = 1LL * k * threshold;

        for(int right = 0; right < arr.size(); right++){
            sum += arr[right];

            if(right - left + 1 == k){
                if(sum >= need) count++;
                sum -= arr[left];
                left++;
            }
        }
        return count;
    }
};