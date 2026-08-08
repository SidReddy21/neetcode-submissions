class Solution {
private:
    vector<vector<int>> ans;
public:

    void helper(vector<int> vec, int sum, vector<int> nums, int target,int j){
        if(sum > target) return;
        if(sum == target) ans.push_back(vec);
        for(int i = j; i < nums.size(); i++){
            vec.push_back(nums[i]);
            helper(vec,sum+nums[i],nums,target,i);
            vec.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++){
            vector<int> vec;
            int sum = nums[i];
            vec.push_back(nums[i]);
            helper(vec,sum,nums,target,i);
        }

        return ans;
    }
};
