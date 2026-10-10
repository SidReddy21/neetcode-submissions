class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0] = 1;
        int curr = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            curr+=nums[i];
            curr%=k;
            curr+=k;
            curr%=k;
            ans+=map[curr];
            map[curr]++;
        }

        return ans;
    }
};


// [4,5,0,-2,-3,1] k=5
// 5 50 50-2-3 0 -2-3 0-2-3 250-2-31  **  7 total
