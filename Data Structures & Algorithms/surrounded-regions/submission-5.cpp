class Solution {
public:
    void solve(vector<vector<char>>& board) {
        //iterate by the edges all 4sides

        for(int i = 0; i < board.size(); i++){
            if(board[i][0] == 'O') dfs(board,i,0);
            if(board[i][board[0].size()-1] == 'O') dfs(board,i,board[0].size()-1);
        }
        for(int j = 0; j < board[0].size(); j++){
            if(board[0][j] == 'O') dfs(board,0,j);
            if(board[board.size()-1][j] == 'O') dfs(board,board.size()-1,j);
        }
        
        // then loop through the whoel matrix - anythin makred as T goes to O and all Os go to X
        // for(int i = 0; i < board.size(); i++){
        //     for(int j = 0; j < board[0].size(); j++){
        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'T') board[i][j] = 'O';
            }
        }
        
    }



    void dfs(vector<vector<char>>& board, int i, int j){
        //if we detect an O run dfs to makr all those Os off as a T
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O') return;
        board[i][j] = 'T';
        dfs(board,i+1,j);
        dfs(board,i-1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1);
    }

};


/*

Input: board = [
  ["X","X","X","X"],
  ["X","O","O","X"],
  ["X","O","O","X"],
  ["X","O","X","X"]
]

*/
