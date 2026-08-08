class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int left = 0;
        int right = 0;
        int MAX = 0;
        unordered_set<char> set;

        while(right < s.size()){
            if(set.contains(s[right])){
                while(s[left] != s[right]){
                    set.erase(s[left++]);
                }
                left++;
            }
            else{
                set.insert(s[right]);
                MAX = max(MAX,(right-left+1));
                cout << left << right << MAX << endl;
            }
            right++;
        }

        return MAX;
    }
};
