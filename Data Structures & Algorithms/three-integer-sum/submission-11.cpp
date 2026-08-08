class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;

        vector<vector<int>> ans;
        while(left < nums.size()){
            if(left > 0 && nums[left] == nums[left-1]){
                left++;
                continue;
            }


            int i = left+1;
            int right = nums.size()-1;
            while(i < right){
                if(i > left+1 && nums[i] == nums[i-1]){
                    i++;
                    continue;
                }else if(right < nums.size()-1 && nums[right] == nums[right+1]){
                    right--;
                    continue;
                }
                else if(nums[i]+nums[left]+nums[right] > 0) right--;
                else if(nums[i]+nums[left]+nums[right] < 0) i++;
                else{
                    ans.push_back({nums[left],nums[i],nums[right]});
                    // cout << left << i << right<< endl;
                    i++;
                    
                }
            }
            left++;
        }

        return ans;
        //[-4,-1,-1,0,1,2]
    }
};
