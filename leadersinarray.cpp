class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        int max = INT_MIN;
        int n=arr.size();
        std::vector<int> leaders;
        for(int i=n-1; i>=0; i--){
            if(arr[i]>=max){
                max=arr[i];                      // if an arr[i] is greater than max it is definitely  greater than all right elements!
                leaders.push_back(arr[i]);
                
            }
            
        }
        reverse(leaders.begin(),leaders.end());
        return leaders;
        
    }
};