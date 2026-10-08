class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> countGap;

        for(vector<int>& row : wall){
            int total = 0;
            for(int i = 0; i < row.size()-1; i++){
                total+=row[i];
                countGap[total]++;
            }
        }

        int MAX = 0;
        for(auto& p : countGap){
            MAX = max(MAX, p.second);
        }

        return wall.size()-MAX;
    }
};