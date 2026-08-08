class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int j = 0; j <= n; j++){
            int sum = 0;
            int i = j;
            while(i){
                sum+=(1 & i);
                i >>= 1;
            }
            ans.push_back(sum);
        }

        return ans;
    }
};
