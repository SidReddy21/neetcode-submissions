class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            if(board[i][0] == 'O') dfs(board,i,0);
            if(board[i][board[0].size()-1] == 'O') dfs(board,i,board[0].size()-1);
        }
        for(int j = 0; j < board[0].size(); j++){
            if(board[0][j] == 'O') dfs(board,0,j);
            if(board[board.size()-1][j] == 'O') dfs(board,board.size()-1,j);
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'T') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }

    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<char>>& board, int i, int j){
        board[i][j] = 'T';
        for(auto dir : dirs){
            i+=dir[0];
            j+=dir[1];
            if(i >= 0 && j >= 0 && i < board.size() && j < board[0].size() && board[i][j] == 'O') dfs(board,i,j);
            i-=dir[0];
            j-=dir[1];
        }
    }
};
