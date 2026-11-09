class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = (nums.size()*(nums.size()+1))/2;

        int ans = 0;
        for(int num : nums) ans+=num;

        return total-ans;

    }
};
