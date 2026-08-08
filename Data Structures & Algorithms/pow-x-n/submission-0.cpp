class Solution {
public:

    double myPow(double x, int n) {
        if(n > 1) return x*myPow(x,n-1);
        else if(n == 1) return x; 
        else if(n < 1) return (1.0/x)*myPow(x,n+1);
        else if(n == -1) return (1.0/x);
        return 0;
    }
};
