class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int one = 1;
        int two = 2;
        int ans = 0;
        for(int i = 3; i <= n; i++){
            ans = one+two;
            one = two;
            two = ans;
        }

        return ans;
    }
};
