class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int MAX = nums[0];
        int sum = 0;
        for(int num : nums){
            if(sum < 0) sum = 0;
            sum+=num;
            MAX = max(sum,MAX);
        }

        return MAX;
    }
};
