class Solution {
private: 
    vector<vector<int>> ans = {};
public:

    void helper(vector<int> nums, int target, int sum, vector<int> stuff, int j){
        if(sum > target) return;
        if(sum == target) ans.push_back(stuff);
        for(int i = j; i < nums.size(); i++){
            sum+=nums[i];
            stuff.push_back(nums[i]);
            helper(nums,target,sum,stuff,i);
            sum-=nums[i];
            stuff.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end(),greater<>());
        helper(nums,target,0,{},0);

        return ans;
    }
};
