class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0] = 1;
        int curr = 0;
        int count = 0;
        for(int& num : nums){
            curr+=num;
            if(map.contains(curr-k)) count+=(map[curr-k]);
            map[curr]++;
        }

        return count;
    }
};