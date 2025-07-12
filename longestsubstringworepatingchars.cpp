class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256,-1);
        int l=0;
        int r=0;
        int maxlen=0;
        int n = s.size();
        while(r<n){
            if(hash[s[r]]!=-1 && hash[s[r]]>=l){  // in the substring and repeated
                l = hash[s[r]]+1;           // move l, // shrink substring!
            }
            int len = r-l+1;
            maxlen=max(len,maxlen);

            // the index for that element to be stored
            hash[s[r]]=r;
            r++;
        }
        return maxlen;
        
    }
};