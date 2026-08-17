class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<vector<int>> freq(nums.size());

        for(int num : nums){
            map[num]++;
        }
        for(auto pair : map){
            freq[pair.second-1].push_back(pair.first);
        }

        vector<int> ans;
        for(int i = freq.size()-1; i >= 0; i--){
            while(!freq[i].empty()){
                ans.push_back(freq[i].back());
                freq[i].pop_back();
            }
            if(ans.size() == k) break;
        }

        return ans;
    }
};
