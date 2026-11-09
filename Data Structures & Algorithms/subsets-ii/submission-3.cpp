class Solution {

private:
    vector<vector<int>> ans;
public:

    

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp = {};
        ans.push_back(temp);
        dfs(nums,temp,0);
        return ans;
    }

    void dfs(vector<int>& nums,vector<int>& temp, int x){
        for(int i = x; i < nums.size(); i++){
            if(i > x && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            ans.push_back(temp);
            dfs(nums,temp,i+1);
            temp.pop_back();
        }
    }
};
