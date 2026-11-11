class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> a = {};
        ans.push_back({});
        helper(nums,0,a);
        return ans;
    }

    void helper(vector<int>& nums,int start,vector<int>& temp){
        for(int i = start; i < nums.size(); i++){
            temp.push_back(nums[i]);
            ans.push_back(temp);
            helper(nums,i+1,temp);
            temp.pop_back();
        }
    }
};
