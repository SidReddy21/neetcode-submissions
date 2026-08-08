class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,int> map;
        vector<vector<string>> ans;

        for(string s : strs){
            string temp = s;
            sort(temp.begin(),temp.end());
            if(map.contains(temp)) ans[map[temp]].push_back(s);
            else{
                map[temp] = ans.size();
                ans.push_back({s});
            }
        }

        return ans;
    }
};
