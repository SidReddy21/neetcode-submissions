class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<unordered_set<int>> freq(nums.size());

        for(int num : nums){
            if(map[num] > 0) freq[map[num]-1].erase(num);
            map[num]++;
            freq[map[num]-1].insert(num);
        }

        vector<int> ans;
        for(int i = freq.size()-1; i >= 0; i--){
            while(!freq[i].empty()){
                ans.push_back(*freq[i].begin());
                freq[i].erase(freq[i].begin());
            }
            if(ans.size() == k) break;
        }

        return ans;
    }
};
