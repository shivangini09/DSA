class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int r=0;
        int maxlen=0;
        map<int,int> mpp;
        while(r<fruits.size()){
            mpp[fruits[r]]++;
            if(mpp.size()>2){
                mpp[fruits[l]]--;      // start removing fruit types
                if(mpp[fruits[l]]==0){
                    mpp.erase(fruits[l]);   // it is no longer in basket, we have taken it out
                }
                l++;
            }
            else{
                maxlen = max(maxlen,r-l+1);         // max length subarray return
            }
            r++;

        }
        return maxlen;
        
    }
};