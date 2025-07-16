class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort based on ending time
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int count =1;
        int endtime = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]>=endtime){
                // event is not overlapping
                count++;     // event can happen
                endtime = intervals[i][1];      // endtime is now updated
            }
        }
        return intervals.size()-count;

        
        
    }
};