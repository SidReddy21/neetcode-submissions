class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> map;
        map[0] = 1;
        int ans = 0;
        int total = 0;
        for(int& num : nums){
            total+=num;
            if(map.contains(total-goal)) ans+=map[total-goal];
            map[total]++;
        }

        return ans;
    }
};

//goal = total-map[x]