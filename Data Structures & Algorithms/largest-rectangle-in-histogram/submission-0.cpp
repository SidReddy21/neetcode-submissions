class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> rectangles(1000,0);
        for(int j = 0; j < rectangles.size(); j++){
            if(j < heights[0]) rectangles[j]++;
            else break;
        }

        int MAX = heights[0];
        for(int i = 1; i < heights.size(); i++){
            if(heights[i] >= heights[i-1]){
                for(int j = 0; j < heights[i]; j++) rectangles[j]++;
            }else{
                for(int j = 0; j < heights[i]; j++) rectangles[j]++;
                for(int j = heights[i]; j < heights[i-1]; j++){
                    MAX = max(MAX,rectangles[j]*(j+1));
                    rectangles[j] = 0;
                }
            }
        }

        for(int j = 0; j < rectangles.size(); j++){
            MAX = max(MAX,rectangles[j]*(j+1));
        }

        return MAX;
    }
};
