class Solution {
public:
    int trap(vector<int>& height) {

        int left = 0;
        int right = height.size()-1;
        int leftMax = height[left];
        int rightMax = height[right];
        int ans = 0;

        while(left <= right){
            if(leftMax < rightMax){
                if(height[left] > leftMax) leftMax = height[left];
                else ans+=(leftMax-height[left]);
                left++;
            }else{
                if(height[right] > rightMax) rightMax = height[right];
                else ans+=(rightMax-height[right]);
                right--;
            }
            cout << ans << endl;
        }

        return ans;
    }
};
/*

09 0
19 0
18 0
17 0
16 0
26 2
36 2
35 

*/





// 0 2 0 3 1 0 1 3 2 1

