class Solution {
  public:

    int findFloor(vector<int>& arr, int x) {
        // Your code here
        int low = 0;
        int high = arr.size()-1;
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]>x){
                high = mid-1;
            }
            else if(arr[mid]<=x){
                ans = mid;       // we will wait until we get the best
                low = mid+1;
            }
        }
        return ans;
    }
};
