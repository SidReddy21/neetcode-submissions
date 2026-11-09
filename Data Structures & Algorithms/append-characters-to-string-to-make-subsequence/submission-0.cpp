class Solution {
public:
    int appendCharacters(string s, string t) {
        int iS = 0;
        int iT = 0;
        while(iS < s.size() && iT < t.size()){
            if(s[iS] == t[iT]){
                iS++;
                iT++;
            }else iS++;
        }

        return t.size()-iT;
    }
};