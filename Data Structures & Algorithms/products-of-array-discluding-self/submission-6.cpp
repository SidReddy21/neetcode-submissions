class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0] = 1;
        for(int i = 1; i < ans.size(); i++){
            ans[i] = ans[i-1]*nums[i-1];
        }
        int suffix = 1;
        for(int i = ans.size()-2; i >= 0; i--){
            suffix*=nums[i+1];
            ans[i]*=suffix;
            
        }
        return ans;
    }
};


// nums = 1,2,4,6
// prefix = 1,1,2,8
// suffix = 48,24,6,1
// ans = 48,24,12,8
