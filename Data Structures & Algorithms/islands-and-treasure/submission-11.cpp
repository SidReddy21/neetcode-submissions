class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // Multi-source BFS
        queue<pair<int,int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0) q.push({i,j});
            }
        }

        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        int count = 0;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(auto dir : dirs){
                i+=dir[0];
                j+=dir[1];
                if(i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && grid[i][j] == 2147483647){
                    grid[i][j] = grid[i-dir[0]][j-dir[1]]+1;
                    q.push({i,j});
                }
                i-=dir[0];
                j-=dir[1];
            }
        }
    }
};
