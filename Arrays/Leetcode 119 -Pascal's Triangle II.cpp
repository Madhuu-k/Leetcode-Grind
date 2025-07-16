// Problem Link: https://leetcode.com/problems/pascals-triangle-ii/?envType=problem-list-v2&envId=array
// Time Complexity: O(k²)

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle;
        triangle.push_back({1}); // First row

        for (int i = 1; i <= rowIndex; ++i) {
            vector<int> row;
            vector<int>& prev = triangle[i - 1];

            row.push_back(1); // First element

            for (int j = 1; j < prev.size(); ++j) {
                row.push_back(prev[j - 1] + prev[j]);
            }

            row.push_back(1); // Last element
            triangle.push_back(row);
        }

        return triangle[rowIndex];
    }
};
