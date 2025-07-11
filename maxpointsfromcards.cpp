class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0;
        int rsum = 0;
        int maxsum;
        int n = cardPoints.size();
        for(int i=0; i<k; i++){
            lsum=lsum+cardPoints[i];    // what if we take all cards from start!
        }
        maxsum = lsum;
        int rightindex = n-1;           // keep the right sum indexing
        for(int j = k-1; j>=0; j--){
            lsum = lsum-cardPoints[j];           // left se ek card hataya
            rsum = rsum+cardPoints[rightindex];      // right se ek card joda
            rightindex--;

            maxsum = max(maxsum,lsum+rsum);
        }
        return maxsum;
        
    }
};