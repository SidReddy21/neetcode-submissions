class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int num : nums) set.insert(num);

        int MAX = 0;
        for(int num : set){
            if(set.contains(num-1)) continue;
            else{
                int count = 0;
                while(set.contains(num++)){
                    count++;
                }
                MAX = max(MAX,count);
            }
        }

        return MAX;
    }
};
