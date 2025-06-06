class Solution {
  public:
    bool arraySortedOrNot(vector<int> &arr) {
        int n = arr.size();
        for(int i=0; i<n-1; i++){
            if(arr[i]<=arr[i+1]){       // if prev element is smaller or equal it is fine
                
            }
            else{
                return false;
            }
        }
        return true;
        
    }
};