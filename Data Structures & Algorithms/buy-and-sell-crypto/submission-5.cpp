class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int MIN = prices[0];
        int ans = 0;
        for(int i = 1; i < prices.size(); i++){
            MIN = min(MIN,prices[i]);
            ans = max(ans,prices[i]-MIN);
        }

        return ans;
    }
};
