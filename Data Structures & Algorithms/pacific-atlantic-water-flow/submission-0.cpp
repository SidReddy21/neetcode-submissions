class Solution {
public:

    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> atl(heights.size(),vector<bool>(heights[0].size(),0));
        vector<vector<bool>> pac(heights.size(),vector<bool>(heights[0].size(),0));
        for(int i = 0; i < heights.size(); i++){
            dfs(heights,pac,i,0);
            dfs(heights,atl,i,heights[0].size()-1);
        }
        for(int j = 0; j < heights[0].size(); j++){
            dfs(heights,pac,0,j);
            dfs(heights,atl,heights.size()-1,j);
        }

        vector<vector<int>> ans;
        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                if(atl[i][j] && pac[i][j]) ans.push_back({i,j});
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int i, int j){
        ocean[i][j] = true;
        for(auto dir : dirs){
            int r = i+dir[0];
            int c = j+dir[1];
            if(r >= 0 && c >= 0 && r < heights.size() && c < heights[0].size() && !ocean[r][c] && heights[r][c] >= heights[i][j]) dfs(heights,ocean,r,c);
        }
    }
};
