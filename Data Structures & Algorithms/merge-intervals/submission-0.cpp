class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(vector<int> interval : intervals){
            if(end >= interval[0]) end = max(interval[1],end);
            else{
                ans.push_back({start,end});
                start = interval[0];
                end = interval[1];
            }
        }
        ans.push_back({start,end});

        return ans;
    }
};
