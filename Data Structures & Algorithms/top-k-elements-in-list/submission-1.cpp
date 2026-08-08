class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int> ans;

        unordered_map<int,int> map;
        for(int num : nums){
            map[num]++;
        }

        priority_queue<pair<int,int>> pq;
        for(auto p : map){
            pq.push({p.second,p.first});
        }
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
