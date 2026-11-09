class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int MAX = INT_MIN;
        int sum = 0;
        for(int& num : nums){
            sum+=num;
            MAX = max(MAX,sum);
            if(sum < 0) sum = 0;
        }

        return MAX;
    }
};
