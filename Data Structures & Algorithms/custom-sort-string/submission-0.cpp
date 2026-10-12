class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> map;
        for(char& c : s) map[c]++;
        string ans = "";
        for(char& c : order){
            ans.append(map[c],c);
            map[c] = 0;
        }
        for(auto& p : map){
            ans.append(p.second,p.first);
        }

        return ans;
    }
};