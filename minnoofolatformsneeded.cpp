class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int n = arr.size();
        int a = 0, b = 0;
        int count = 0, maxcount = 0;
        
        while (a < n && b < n) {
            if (arr[a] <= dep[b]) {
                count++; // Train arrives, platform needed
                a++;
            } else {
                count--; // Train departs, platform freed
                b++;
            }
            maxcount = max(maxcount, count);
        }
        
        return maxcount;
    }
};
