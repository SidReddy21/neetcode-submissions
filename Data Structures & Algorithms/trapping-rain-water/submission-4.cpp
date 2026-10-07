class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int leftMax= height[left];
        int rightMax = height[right];
        int ans = 0;

        while(left < right){
            if(leftMax < rightMax)
                if(height[++left] < leftMax) ans+=(leftMax-height[left]);
                else leftMax = height[left];
            else
                if(height[--right] < rightMax) ans+=(rightMax-height[right]);
                else rightMax = height[right];
        }

        return ans;
    }
};
