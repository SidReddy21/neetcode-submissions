class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        
        int MAX = 0;
        while(left < right){
            MAX = max(min(heights[left],heights[right])*(right-left),MAX);
            if(heights[left] <= heights[right]) left++;
            else right--;
        }

        return MAX;
    }
};
