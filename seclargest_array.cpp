class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // edge cases 
        if (arr.size() < 2) return -1;  // Not enough elements

        int largest = arr[0];
        int second = INT_MIN;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > largest) {
                second = largest;
                largest = arr[i];
            } else if (arr[i] < largest && arr[i] > second) {
                second = arr[i];
            }
        }

        return (second == INT_MIN) ? -1 : second;  // Handle all equal case
    }
};
