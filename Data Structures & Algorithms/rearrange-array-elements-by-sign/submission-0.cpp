class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> neg;
        vector<int> pos;
        vector<int> ans;
        for(int& num : nums){
            if(num < 0) neg.push_back(num);
            else pos.push_back(num);
        }

        for(int i = 0; i < pos.size(); i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }

        return ans;
    }
};