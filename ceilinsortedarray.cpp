// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int low =0;
        int high = arr.size()-1;
        int ans =-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]<x){
                low = mid+1;
            }
            else if(arr[mid]>=x){
                ans = mid;
                high = mid-1;  // maybe we'll find a better one
            }
        }
        return ans;
    }
};