class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            unordered_set<char> set;
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.') continue;
                if(set.contains(board[i][j])) return false;
                else set.insert(board[i][j]);
            }
        }

        for(int i = 0; i < board.size(); i++){
            unordered_set<char> set;
            for(int j = 0; j < board[0].size(); j++){
                if(board[j][i] == '.') continue;
                if(set.contains(board[j][i])) return false;
                else set.insert(board[j][i]);
            }
        }

        int x = 3;
        for(int r = 0; r < 3; r++){
            for(int c = 0; c < 3; c++){
                unordered_set<char> set;
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        if(board[i+x*r][j+x*c] == '.') continue;
                        if(set.contains(board[i+x*r][j+x*c])) return false;
                        else set.insert(board[i+x*r][j+x*c]);
                    }
                }
            }
        }

        return true;
    }
};
