class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count = 0;
        unordered_set<int> set;
        for(int& num : nums){
            set.insert(num);
        }

        for(int num : set){
            if(set.contains(num-1)) continue;
            int temp = 1;
            while(set.contains(++num)) temp++;
            count = max(temp,count);
        }

        return count;
    }
};
