class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        map<int,int> mpp;
        int sum=0;
        int len=0;
        for(int i=0; i<arr.size(); i++){
            sum+=arr[i];
            if(sum==k){
                len=max(len,i+1);
            }
            int needed = sum-k;
            if(mpp.find(needed)!=mpp.end()){
                len = max(len,i-mpp[needed]);
            }
            if(mpp.find(sum)==mpp.end()){
                mpp[sum]=i;
            }
        }
        return len;
    }
};