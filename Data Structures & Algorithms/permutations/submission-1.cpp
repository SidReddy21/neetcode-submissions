class Solution {
public:

    vector<vector<int>> ans;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp = {};
        vector<bool> picks(nums.size(),0);
        dfs(nums,temp,picks,0);
        return ans;
    }

    void dfs(vector<int>& nums, vector<int> & temp, vector<bool>& picks, int count){
        if(count == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(picks[i]) continue;
            temp.push_back(nums[i]);
            picks[i] = true;
            count++;
            dfs(nums,temp,picks,count);
            count--;
            picks[i] = false;
            temp.pop_back();
        }
    }
};
