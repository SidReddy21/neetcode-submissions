class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;

        while(left <= right){
            int mid = left+(right-left)/2;
            if(right == left+1 || left == right) return min(nums[right],nums[left]);
            else if(nums[mid] < nums[right]) right = mid;
            else if(nums[mid] > nums[right]) left = mid;

        }

        return -1;
    }
};

// [6,1,2,3,4,5]