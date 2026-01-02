// Problem Link: https://leetcode.com/problems/sort-an-array/
// Time Complexity: O(n logn)

class Solution {
public:
    void merge(vector<int>& arr, int l, int m, int r){
        int n1 = m - l + 1;
        int n2 = r - m;
        vector<int> L(n1), R(n2);
        for(int i = 0; i < n1; i++) L[i] = arr[l + i];
        for(int j = 0; j < n2; j++) R[j] = arr[m + j + 1];

        int i =0, j = 0, k = l;
        while(i < n1 && j < n2){
            if(L[i] <= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }

        while(i < n1) arr[k++] = L[i++];
        while(j < n2) arr[k++] = R[j++];
    }

    void mergeSort(vector<int>& arr, int l, int r){
        if(l < r){
            int mid = l + (r-l) / 2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid+1, r);
            merge(arr, l, mid, r);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        mergeSort(nums, l, r);
        return nums;
    }
};