class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> map;
        for(int i = 0; i < numbers.size(); i++){
            if(map.contains(target-numbers[i])) return {map[target-numbers[i]]+1,1+i};
            map[numbers[i]] = i;
        }

        return {};
    }
};
