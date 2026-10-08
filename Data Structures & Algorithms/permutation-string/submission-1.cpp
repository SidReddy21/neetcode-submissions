class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<int> letters1(26,0);
        for(char& c: s1) letters1[c-'a']++;
        vector<int> letters2(26,0);
        for(int i = 0; i < s1.size(); i++){
            letters2[s2[i]-'a']++;
        }
        if(letters2 == letters1) return true;
        for(int i = s1.size(); i < s2.size(); i++){
            letters2[s2[i-s1.size()]-'a']--;
            letters2[s2[i]-'a']++;
            if(letters2 == letters1) return true;
        }

        return false;
    }
};
