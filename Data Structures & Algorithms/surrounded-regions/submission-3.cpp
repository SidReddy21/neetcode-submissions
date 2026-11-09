class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            dfs(board,i,0);
            dfs(board,i,board[0].size()-1);
        }
        for(int j = 0; j < board[0].size(); j++){
            dfs(board,0,j);
            dfs(board,board.size()-1,j);
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'T') board[i][j] = 'O';
            }
        }

        // return board;
    }

    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<char>>& board, int i, int j){
        if(board[i][j] == 'O') board[i][j] = 'T';
        else return;

        for(auto dir : dirs){
            int r = i+dir[0];
            int c = j+dir[1];
            if(r >= 0 && c >= 0 && r < board.size() && c < board[0].size()) dfs(board,r,c);
        }
    }
};
