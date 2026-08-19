class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
        {
            return 0;
        }
        int low = 0;
        int high = 1;
        int count = 1;
        int maxCount = 1;
        int n = s.size();
        while(high < n)
        {
            int i = low;
            while(i < high && s[i] != s[high])
            {
                i++;
            }
            if(i < high)
            {
                low = i + 1;
                count = high - low + 1;
            }
            else
            {
                count++;
            }
            maxCount = max(maxCount,count);
            high++;
        }
        return maxCount;
        
    }
};
