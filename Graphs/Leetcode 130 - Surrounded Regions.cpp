// Problem Link: https://leetcode.com/problems/surrounded-regions/
// Time Complexity: O(rows.cols)

class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void dfs(int r, int c, vector<vector<char>>& board){
        board[r][c] = '*';
        int rows = board.size();
        int cols = board[0].size();

        for(int k = 0; k < 4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr >= 0 && nc >= 0 && nr < rows && nc < cols && board[nr][nc] == 'O')
                dfs(nr, nc, board);
        }
    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0; i < rows; i++){
            if(board[i][0] == 'O') dfs(i, 0, board);
            if(board[i][cols - 1] == 'O') dfs(i, cols - 1, board);
        }

        for(int j = 0; j < cols; j++){
            if(board[0][j] == 'O') dfs(0, j, board);
            if(board[rows - 1][j] == 'O') dfs(rows - 1, j, board);
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '*') board[i][j] = 'O';
            }
        }
    }
};