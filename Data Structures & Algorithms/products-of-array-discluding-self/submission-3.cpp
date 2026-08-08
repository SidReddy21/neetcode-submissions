class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        prefix[0] = 1;
        for(int i = 1; i < prefix.size(); i++){
            prefix[i] = prefix[i-1]*nums[i-1];
        }

        // vector<int> suffix(nums.size());
        // suffix[suffix.size()-1] = 1;
        int temp = 1;
        for(int i = prefix.size()-2; i >= 0; i--){
            temp*=nums[i+1];
            prefix[i]*=temp;
        }

        // // vector<int> ans(nums.size());
        // for(int i = 0; i < prefix.size(); i++){
        //     prefix[i] = prefix[i]*suffix[i];
        // }

        return prefix;
    }
};
