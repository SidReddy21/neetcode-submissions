class Solution {
public:
    bool check(vector<int>& nums) {
        int MIN = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < nums[MIN]) MIN = i;
        }

        int curr = nums[MIN];
        for(int i = MIN; i < nums.size(); i++){
            if(nums[i] < curr) return false;
            else curr = nums[i];
        }
        for(int i = 0; i < MIN; i++){
            if(nums[i] < curr) return false;
            else curr = nums[i];
        }

        return true;
    }
};