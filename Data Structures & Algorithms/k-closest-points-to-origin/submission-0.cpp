class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>> maxHeap;
        for(vector<int> point : points){
            maxHeap.push({sqrt((point[0]*point[0])+(point[1]*point[1])),point});
            if(maxHeap.size() > k) maxHeap.pop();
        }

        vector<vector<int>> ans;
        while(maxHeap.size() > 0){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};
