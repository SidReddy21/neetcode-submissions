class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> map;
        vector<vector<string>> ans;
        for(string str : strs){
            string temp = str;
            sort(temp.begin(),temp.end());
            if(map.contains(temp)) ans[map[temp]].push_back(str);
            else{
                map[temp] = ans.size();
                ans.push_back({str});
            }
        }


        return ans;
    }
};
