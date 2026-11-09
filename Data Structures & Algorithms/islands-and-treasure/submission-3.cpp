class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    q.push({i+1,j,1});
                    q.push({i-1,j,1});
                    q.push({i,j+1,1});
                    q.push({i,j-1,1});
                }
            }
        }

        while(!q.empty()){
            int size = q.size();
            for(int k = 0; k < size; k++){
                int i = q.front()[0];
                int j = q.front()[1];
                int dist = q.front()[2];
                q.pop();
                if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] <= 0) continue;

                if(dist < grid[i][j]) grid[i][j] = dist;
                else continue;
                q.push({i+1,j,dist+1});
                q.push({i-1,j,dist+1});
                q.push({i,j+1,dist+1});
                q.push({i,j-1,dist+1});
            }
        }
    }
};
