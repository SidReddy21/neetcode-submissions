class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<int>> rows,cols;
        map<pair<int,int>,unordered_set<int>> squares;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.') continue;
                int num = board[i][j]-'0';
                if(rows[i].contains(num) || cols[j].contains(num) || squares[{i/3,j/3}].contains(num)) return false;
                rows[i].insert(num);
                cols[j].insert(num);
                squares[{i/3,j/3}].insert(num);
            }
        }

        return true;
    }
};
