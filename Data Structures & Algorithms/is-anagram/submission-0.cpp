class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> letters(26,0);
        for(int i = 0; i < s.size(); i++){
            ++letters[s[i]-'a'];
            --letters[t[i]-'a'];
        }

        for(int i : letters){
            if(i != 0) return false;
        }

        return true;
    }
};
