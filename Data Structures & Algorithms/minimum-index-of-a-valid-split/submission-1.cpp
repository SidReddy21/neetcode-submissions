class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> map1, map2;
        for(int i = 0; i < nums.size(); i++){
            map2[nums[i]]++;
        }

        for(int i = 0; i < nums.size(); i++){
            map1[nums[i]]++;
            map2[nums[i]]--;

            if(2*map1[nums[i]] > i+1 && 2*map2[nums[i]] > nums.size()-(i+1)) return i;
        }

        return -1;
    }
};