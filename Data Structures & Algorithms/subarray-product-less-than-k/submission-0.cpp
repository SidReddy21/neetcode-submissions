class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prev = 0;
        int product = 1;
        int ans = 0;
        if(k == 0 || k == 1) return 0;
        for(int i = 0; i < nums.size(); i++){
            product*=nums[i];
            while(prev < nums.size() && product >= k) product/=nums[prev++];
            ans+=(i+1-prev);
        }

        return ans;
    }
};