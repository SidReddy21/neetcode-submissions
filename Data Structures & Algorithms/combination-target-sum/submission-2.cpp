class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(nums,target,0,{},0);
        return ans;
    }

    void dfs(vector<int>& nums, int target, int curr, vector<int> temp, int x){
        if(curr > target) return;
        if(curr == target) ans.push_back(temp);
        for(int i = x; i < nums.size(); i++){
            curr+=nums[i];
            temp.push_back(nums[i]);
            dfs(nums,target,curr,temp,i);
            temp.pop_back();
            curr-=nums[i];
        }
    }
};
