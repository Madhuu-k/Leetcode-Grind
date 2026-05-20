// Problem Link: https://leetcode.com/problems/rotting-oranges/
// Time Complexity: O(rows.cols)

class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int rows = grid.size();
        int cols = grid[0].size();

        int fresh = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2) q.push({i, j});
                else if(grid[i][j] == 1) fresh++;
            }
        }

        int mins = 0;

        while(!q.empty() && fresh > 0){
            int size = q.size();

            while(size--){
                auto [r, c] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr >= 0 && nc >= 0 && nr < rows && nc < cols && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }

            mins++;
        }

        return (fresh == 0) ? mins : -1;
    }
};