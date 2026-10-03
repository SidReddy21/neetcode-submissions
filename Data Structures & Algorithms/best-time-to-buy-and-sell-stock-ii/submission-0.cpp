class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int MIN = prices[0];
        int ans = 0;
        for(int price : prices){
            if(price > MIN){
                ans+=(price-MIN);
                MIN = price;
            }else MIN = min(MIN,price);
        }

        return ans;
    }
};