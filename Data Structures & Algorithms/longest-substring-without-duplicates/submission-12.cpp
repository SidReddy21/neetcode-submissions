class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> letters(128,0);
        int left = 0;
        int MAX = 0;

        for(int right = 0; right < s.size(); right++){
            if(letters[s[right]]){
                while(s[left] != s[right]){
                    letters[s[left]] = false;
                    left++;
                }
                letters[s[left]] = false;
                left++;
            }

            letters[s[right]] = true;
            MAX = max(MAX,right-left+1);
        }

        return MAX;
    }
};

/*

"asbdlfkjbawoilfuheqqqqqqqq"

NO HASING
vector<bool> letters(128,false);
if(letter[character])
letters[character] = true;

xzyxyz

*/
