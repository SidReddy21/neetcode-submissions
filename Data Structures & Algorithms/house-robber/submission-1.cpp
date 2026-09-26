class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0],nums[1]);
        vector<int> houses(nums.size());
        houses[0] = nums[0];
        houses[1] = max(nums[0],nums[1]);
        for(int i = 2; i < houses.size(); i++){
            houses[i] = max(houses[i-2]+nums[i],houses[i-1]);
        }

        return houses.back();
    }
};
