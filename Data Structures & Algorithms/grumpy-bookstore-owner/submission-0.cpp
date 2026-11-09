class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        int sum = 0;

        for(int i = 0; i < customers.size(); i++){
            if(grumpy[i] == 0) sum+=customers[i];
        }
        
        for(int i = 0; i < minutes; i++){
            if(grumpy[i] == 1) sum+=customers[i];
        }
        int MAX = sum;
        for(int i = 0; i < customers.size()-minutes; i++){
            if(grumpy[i] == 1) sum-= customers[i];
            if(grumpy[i+minutes] == 1) sum+=customers[i+minutes];
            MAX = max(MAX,sum);
        }

        return MAX;
    }
};