class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int MAX = 0;
        for(int price : prices){
            MAX = max(MAX,price-buy);
                        buy = min(buy,price);

        }

        return MAX;
    }
};
