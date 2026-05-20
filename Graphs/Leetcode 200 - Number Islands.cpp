// Problem Link: https://leetcode.com/problems/number-of-islands/
// Time Complexity: O(rows.cols)

class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        visited[r][c] = true;
        int rows = grid.size();
        int colons = grid[0].size();

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int k = 0; k < 4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr >= 0 && nr < rows
            && nc >= 0 && nc < colons && grid[nr][nc] == '1' && !visited[nr][nc]) dfs(nr, nc, grid, visited);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int islands = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1' && !visited[i][j]) {
                    dfs(i, j, grid, visited);
                    islands++;
                }
            }
        }

        return islands;
    }
};