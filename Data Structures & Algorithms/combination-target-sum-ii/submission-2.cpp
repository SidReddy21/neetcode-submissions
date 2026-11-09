class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp = {};
        dfs(candidates,target,temp,0,0);
        return ans;
    }
    void dfs(vector<int>& candidates, int target, vector<int>& temp, int curr, int x){
        if(curr > target) return;
        if(curr == target){
            ans.push_back(temp);
            return;
        }
        for(int i = x; i < candidates.size(); i++){
            if(i > x && candidates[i] == candidates[i-1]) continue;
            curr+=candidates[i];
            temp.push_back(candidates[i]);
            dfs(candidates,target,temp,curr,i+1);
            temp.pop_back();
            curr-=candidates[i];
        }
    }
};
