class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int num : nums) set.insert(num);
        int ans = 0;
        for(int num : set){
            if(set.contains(num+1)) continue;
            int count = 1;
            while(set.contains(--num)) count++;
            ans = max(ans,count);
        }

        return ans;
    }
};
