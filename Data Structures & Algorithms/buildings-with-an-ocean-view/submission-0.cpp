class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int MAX = heights[heights.size()-1];
        unordered_set<int> set;
        set.insert(heights.size()-1);
        for(int i = heights.size()-1; i >= 0; i--){
            if(heights[i] > MAX) set.insert(i);
            MAX = max(MAX,heights[i]);
        }

        vector<int> ans;
        for(int i = 0; i < heights.size(); i++){
            if(set.contains(i)) ans.push_back(i);
        }

        return ans;
    }
};