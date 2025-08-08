// Problem Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
// Time Complexity: O(log(min(n, m)))

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int k = (n + m + 1) / 2;
        if(nums1.size() < nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int low = max(0, k - m); int high = min(k, n);
        while(low <= high){
            int cutA = (low + high) / 2;
            int cutB = k - cutA;

            int l1 = (cutA == 0) ? INT_MIN : nums1[cutA - 1];
            int l2 = (cutB == 0) ? INT_MIN : nums2[cutB - 1];
            int r1 = (cutA == n) ? INT_MAX : nums1[cutA];
            int r2 = (cutB == m) ? INT_MAX : nums2[cutB];

            if(l1 <= r2 && l2 <= r1){
                if((n + m) % 2 == 0) return (max(l1, l2) + min(r1, r2)) / 2.0;
                else return max(l1, l2);
            }
            else if(l1 > r2) high = cutA - 1;
            else low = cutA + 1;
        }
        return -1;
    }
};