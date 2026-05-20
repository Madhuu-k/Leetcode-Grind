// Problem Link: https://leetcode.com/problems/flood-fill/description/
// Time Complexity: O(rows.cols)

class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void dfs(int r, int c, int color, int orginal, vector<vector<int>>& image, vector<vector<bool>>& visited){
        visited[r][c] = true;
        image[r][c] = color;
        int rows = image.size();
        int colon = image[0].size();

        for(int k = 0; k < 4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr >= 0 && nc >= 0 && nr < rows && nc < colon && !visited[nr][nc] && image[nr][nc] == orginal){
                dfs(nr, nc, color, orginal, image, visited);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orginal = image[sr][sc];
        if(orginal == color) return image;

        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));

        dfs(sr, sc, color, orginal, image, visited);

        return image;
    }
};