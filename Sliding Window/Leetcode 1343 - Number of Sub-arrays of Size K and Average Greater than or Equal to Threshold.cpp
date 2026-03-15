// Problem Link: https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
// Time Complexity: O(n)

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int left = 0, count = 0, sum = 0;
        for(int right = 0; right < arr.size(); right++){
            sum += arr[right];
            while(right - left + 1 == k){
                double avg = sum / k;
                if(avg >= threshold) count++;
                sum -= arr[left];
                left++;
            }
        }
        return count;
    }
};