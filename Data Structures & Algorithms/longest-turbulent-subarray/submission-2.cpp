class Solution {

private:
int ans = 0;
public:
    int down(vector<int>& arr, int i, int curr){
        if(i < arr.size() && arr[i] < arr[i-1]){
            return up(arr,i+1,curr+1);
        }else{
            ans = max(curr,ans);
            return i;
        }
    }

    int up(vector<int>& arr, int i, int curr){
        if(i < arr.size() && arr[i] > arr[i-1]){
            return down(arr,i+1,curr+1);
        }else{
            ans = max(curr,ans);
            return i;
        }
    }

    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() == 1) return 1;

        int i = 1;
        int curr = 1;

        while(i < arr.size()){
            if(arr[i] > arr[i-1]) {
                i = up(arr,i,curr);
            }else if(arr[i] < arr[i-1]){
                i = down(arr,i,curr);
            }else i++;
        }

        if(ans == 0) return 1;
        return ans;
    }
};