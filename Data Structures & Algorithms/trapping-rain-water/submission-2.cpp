class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxLeft = height[left];
        int maxRight = height[right];
        int ans = 0;

        while(left < right){
            if(maxLeft < maxRight){
                left++;
                if(height[left] < maxLeft) ans+=(maxLeft-height[left]);
                else maxLeft = height[left];
            }else{
                right--;
                if(height[right] < maxRight) ans+=(maxRight-height[right]);
                else maxRight = height[right];
            }
        }

        return ans;
    }
};
