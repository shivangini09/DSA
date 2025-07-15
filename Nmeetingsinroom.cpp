class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int, int>> meetings;

        // Pair each meeting's end time with its start time
        for (int i = 0; i < n; ++i) {
            meetings.push_back({end[i], start[i]});
        }

        // Sort meetings by end time
        sort(meetings.begin(), meetings.end());

        int count = 1;  // Always select the first meeting
        int freetime = meetings[0].first;

        // Iterate through the remaining meetings
        // we are trying to do tasks which end early first
        for (int i = 1; i < n; ++i) {
            if (meetings[i].second > freetime) {
                count++;
                freetime = meetings[i].first;
            }
        }

        return count;
    }
};