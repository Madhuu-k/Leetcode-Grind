// Problem Link: https://leetcode.com/problems/01-matrix/
// Time Complexity: O(rows.cols)

class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, -1));
        queue<pair<int, int>> q;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nc >= 0 && nr < rows && nc < cols && dist[nr][nc] == -1){
                    q.push({nr, nc});
                    dist[nr][nc] = dist[r][c] + 1;
                }
            }
        }

        return dist;
    }
};