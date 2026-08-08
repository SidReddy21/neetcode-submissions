class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> letters1(26,0);
        vector<int> letters2(26,0);

        // if(s1.size() > s2.size()) return false;

        for(char c : s1){
            letters1[c-'a']++;
        }


        // s1 = "abc", s2 = "leee cab"
        for(int i = 0; i < s1.size(); i++){
            letters2[s2[i]-'a']++;
        }
        
        for(int i = s1.size(); i < s2.size(); i++){
            if(letters1 == letters2) return true;
            letters2[s2[i-s1.size()]-'a']--;
            letters2[s2[i]-'a']++;
        }

        if(letters1 == letters2) return true;

        return false;
    }
};
