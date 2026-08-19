class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int MAX = 0;
        for(int price : prices){
            buy = min(buy,price);
            MAX = max(MAX,price-buy);
        }

        return MAX;
    }
};
