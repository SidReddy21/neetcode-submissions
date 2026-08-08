class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;

        while(set.contains(n) == 0 && n != 1){
            set.insert(n);
            int sum = 0;
            while(n){
                sum+=(pow((n%10),2));
                n/=10;
            }
            n = sum;
        }

        return n==1;
    }
};
