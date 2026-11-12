class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        int sum = 0;
        for(int i = 0; i < candidates.size(); i++){
            if(i > 0 && candidates[i] == candidates[i-1]) continue;
            sum+=candidates[i];
            temp.push_back(candidates[i]);
            dfs(candidates,temp,sum,target,i+1);
            temp.pop_back();
            sum-=candidates[i];
        }
        return ans;
    }
    void dfs(vector<int>& candidates, vector<int>& temp, int sum, int target, int j){
        if(sum > target) return;
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        for(int i = j; i < candidates.size(); i++){
            if(i > j && candidates[i] == candidates[i-1]) continue;
            sum+=candidates[i];
            temp.push_back(candidates[i]);
            dfs(candidates,temp,sum,target,i+1);
            temp.pop_back();
            sum-=candidates[i];
        }
    }
};
