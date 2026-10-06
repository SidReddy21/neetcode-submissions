class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> map;
        int MAX = -1;
        for(int& num : nums){
            map[num]++;
            if(MAX == -1) MAX = num;
            MAX = map[MAX] > map[num] ? MAX : num;
        }
        int leftCount = 0;
        int rightCount = map[MAX];
        cout << MAX;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == MAX){
                leftCount++;
                rightCount--;
            }

            if(leftCount > (i+1)/2 && rightCount > (nums.size()-1-i)/2) return i;
        }
        return -1;
    }
};