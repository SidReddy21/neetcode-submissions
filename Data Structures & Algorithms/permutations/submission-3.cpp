class Solution {
public:

    vector<vector<int>> ans;

    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums,0);
        return ans;
    }

    void dfs(vector<int>& nums, int x){
        if(x == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = x; i < nums.size(); i++){
            swap(nums[i],nums[x]);
            dfs(nums,x+1);
            swap(nums[i],nums[x]);
        }
    }
};
