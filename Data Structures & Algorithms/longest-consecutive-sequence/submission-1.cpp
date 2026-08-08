class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        int MAX = 0;
        for(const int num : nums){
            set.insert(num);
        }
        for(int num : nums){
            int len = 1;
            if(set.contains(num-1)) continue;
            while(set.contains(++num)) len++;
            MAX = max(MAX,len);
        }

        return MAX;
    }
};
