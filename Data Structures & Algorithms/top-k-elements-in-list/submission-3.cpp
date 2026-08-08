class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> map;
        vector<vector<int>> freq(nums.size()+1);
        for(int num : nums){
            map[num]++;
        }

        for(auto p : map){
            freq[p.second].push_back(p.first);
        }

        vector<int> ans;
        int count = 0;
        for(int i = freq.size()-1; i >= 0; i--){
            if(count == k) break;
            for(int i : freq[i]){
                ans.push_back(i);
                count++;
            }
        }

        return ans;
    }
};
