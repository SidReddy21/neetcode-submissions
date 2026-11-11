class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        queue<pair<int,int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2) q.push({i,j});
                else if(grid[i][j] == 1) fresh++;
            }
        }

        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            if(fresh == 0) return count;
            count++;
            for(int k = 0; k < size; k++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(auto dir : dirs){
                    i+=dir[0];
                    j+=dir[1];
                    if(i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && grid[i][j] == 1){
                        grid[i][j] = 2;
                        fresh--;
                        q.push({i,j});
                    }
                    i-=dir[0];
                    j-=dir[1];
                }
            }
        }

        return fresh > 0 ? -1 : count;
    }
};
