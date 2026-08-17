class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int left = 0;
        for(int right = 1; right < prices.size(); right++){
            if(prices[right] < prices[left]) left = right;
            else ans = max(ans,prices[right]-prices[left]);
        }

        return ans;
    }
};
