class Solution {
public:

    vector<vector<int>> ans;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp = {};
        unordered_set<int> set = {};
        dfs(nums,temp,set);
        return ans;
    }

    void dfs(vector<int>& nums, vector<int> & temp, unordered_set<int>& set){
        if(set.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(set.contains(i)) continue;
            temp.push_back(nums[i]);
            set.insert(i);
            dfs(nums,temp,set);
            set.erase(i);
            temp.pop_back();
        }
    }
};
