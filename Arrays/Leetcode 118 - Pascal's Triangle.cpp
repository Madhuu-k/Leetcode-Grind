// Problem Link: https://leetcode.com/problems/pascals-triangle/description/?envType=problem-list-v2&envId=array
// Time Complexity: O(numRows²)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};

        vector<vector<int>> triangle;
        triangle.push_back({1});  // First row

        for (int i = 1; i < numRows; ++i) {
            vector<int> row;
            vector<int>& prevRow = triangle[i - 1];

            row.push_back(1); // First element is always 1

            for (int j = 1; j < prevRow.size(); ++j) {
                row.push_back(prevRow[j - 1] + prevRow[j]);
            }

            row.push_back(1); // Last element is always 1
            triangle.push_back(row);
        }

        return triangle;
    }
};
