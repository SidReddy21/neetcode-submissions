class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int MIN = prices[0];
        int MAX = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < MIN) MIN = prices[i];
            else MAX = max(MAX, prices[i]-MIN);
        }

        return MAX;
    }
};
