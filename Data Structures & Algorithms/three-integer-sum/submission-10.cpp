class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size()-1;

        vector<vector<int>> ans;
        while(left < right){
            if(left > 0 && nums[left] == nums[left-1]){
                left++;
                continue;
            }

            for(int r = right; r > left; r--){
                if(r < nums.size()-1 && nums[r] == nums[r+1]){
                // r--;
                continue;
                }

                for(int i = left+1; i < r; i++){
                    if(nums[left]+nums[i]+nums[r] == 0){
                        ans.push_back({nums[left],nums[i],nums[r]});
                        break;
                    }else if(nums[left]+nums[i]+nums[r] > 0) break;
                }
            }
            left++;
        }

        return ans;
        //[-4,-1,-1,0,1,2]
    }
};
