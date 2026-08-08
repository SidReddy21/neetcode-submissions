class Solution {
public:

    int bfs(int i, int j, vector<vector<int>>& grid ){
        int count = 1;
        if(grid[i][j] == 1) grid[i][j] = 0;
        else return 0;

        if(i > 0) count+=bfs(i-1,j,grid);
        if(i < grid.size()-1) count+=bfs(i+1,j,grid);
        if(j > 0) count+=bfs(i,j-1,grid);
        if(j < grid[0].size()-1) count+=bfs(i,j+1,grid);

        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int MAX = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) MAX = max(MAX,bfs(i,j,grid));
            }
        }
        return MAX;
    }
};
