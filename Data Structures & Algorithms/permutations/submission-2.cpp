class Solution {
public:

    vector<vector<int>> ans;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp = {};
        dfs(nums,temp,0);
        return ans;
    }

    void dfs(vector<int>& nums, vector<int> & temp, int x){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = x; i < nums.size(); i++){
            temp.push_back(nums[i]);
            swap(nums[i],nums[x]);
            dfs(nums,temp,x+1);
            swap(nums[i],nums[x]);
            temp.pop_back();
        }
    }
};
