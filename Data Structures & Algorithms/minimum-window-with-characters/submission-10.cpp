class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> lettersT(300,0);
        for(char c : t) lettersT[c]++;
        int unique = 0;
        for(int i = 0; i < lettersT.size(); i++) if(lettersT[i] > 0) unique++;

        vector<int> lettersS(300,0);
        int left = 0;
        int right = 0;
        int MIN = INT_MAX;
        int ansLeft,ansRight;
        int curr = 0;
        while(right < s.size()){
            if(lettersS[s[right]]++ == lettersT[s[right]]-1) curr++;
            while(curr == unique){
                if(MIN > right-left+1){
                    MIN = right-left+1;
                    ansLeft = left;
                    ansRight = right;
                }
                if(lettersS[s[left]]-- == lettersT[s[left]]) curr--;
                left++;
            }

            right++;
        }

        return MIN == INT_MAX ? "" : s.substr(ansLeft,ansRight-ansLeft+1);
    }
};
