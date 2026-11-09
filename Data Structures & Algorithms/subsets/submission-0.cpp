class Solution {
public:

    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums,0,{});
        ans.push_back({});
        return ans;
    }

    void dfs(vector<int>& nums, int x, vector<int> temp){
        for(int i = x; i < nums.size(); i++){
            temp.push_back(nums[i]);
            ans.push_back(temp);
            dfs(nums,i+1,temp);
            temp.pop_back();
        }
    }
};
