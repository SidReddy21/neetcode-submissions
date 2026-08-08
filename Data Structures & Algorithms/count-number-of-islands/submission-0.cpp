class Solution {
public:

    void(bfs)(int i, int j, vector<vector<char>>& grid){
        if(grid[i][j] == '1') grid[i][j] = '0';
        else return;

        if(i > 0) bfs(i-1,j,grid);
        if(i < grid.size()-1) bfs(i+1,j,grid);
        if(j > 0) bfs(i,j-1,grid);
        if(j < grid[0].size()-1) bfs(i,j+1,grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    bfs(i,j,grid);
                    count++;
                }
            }
        }

        return count;
    }
};
