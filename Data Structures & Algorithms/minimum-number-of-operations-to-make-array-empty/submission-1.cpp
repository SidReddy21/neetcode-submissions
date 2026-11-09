class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int& num : nums){
            map[num]++;
        }
        int ans = 0;
        for(auto& p : map){
            if(p.second == 1) return -1;
            ans+=((p.second+2)/3);
        }

        return ans;
    }
};