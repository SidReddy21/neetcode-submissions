class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int num = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1) num++;
            }
        }

        int count = 0;
        int minutes = 0;
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            if(count == num) return minutes;
            minutes++;
            int size = q.size();
            for(int k = 0; k < size; k++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(auto& dir : dirs){
                    i+=dir[0];
                    j+=dir[1];
                    if(i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && grid[i][j] == 1){
                        grid[i][j] = 2;
                        count++;
                        q.push({i,j});
                    }
                    i-=dir[0];
                    j-=dir[1];
                }
            }

            for(int i = 0; i < grid.size(); i++){
                for(int j = 0; j < grid[0].size(); j++){
                    cout << grid[i][j] << " ";
                }
                cout << endl;
            }
            cout << "minutes: " << minutes << "  count:" << count << endl;
        }

        if(count == num) return minutes;
        else return -1;
    }
};
