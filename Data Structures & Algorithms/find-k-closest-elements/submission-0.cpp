class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        for(int& num : arr){
            minHeap.push({abs(x-num),num});
        }

        vector<int> ans;
        for(int i =0 ; i < k; i++){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};