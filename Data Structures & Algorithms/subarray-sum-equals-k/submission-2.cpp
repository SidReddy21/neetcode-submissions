class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0] = 1;
        int runningSum = 0;
        int count = 0;

        for(int& num : nums){
            runningSum+=num;
            
            if(map.contains(runningSum-k)) count+=(map[runningSum-k]);
            map[runningSum]++;
        }

        return count;
    }
};
//elemnts must be a contigiuous subarray
// prioritiz time over apce

// [1,2,-1,-3,4,5,6] k=1
            //   ^
// [1,2,-1,-3,4,5,6]
    //   ^

// k=runningSum-(Val in the hashmap)
// (val in the hashmap) = runningSum-k
