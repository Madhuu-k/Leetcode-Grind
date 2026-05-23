// Problem Link: https://leetcode.com/problems/max-area-of-island/
// Time Complexity: O(R.C)

class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c){
        visited[r][c] = true;
        int rows = grid.size();
        int cols = grid[0].size();
        int area = 1;

        for(int k = 0; k < 4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr >= 0 && nc >= 0 && nr < rows && nc < cols && !visited[nr][nc] && grid[nr][nc] == 1){
                area += dfs(grid, visited, nr, nc);
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    int area = dfs(grid, visited, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;

    }
};