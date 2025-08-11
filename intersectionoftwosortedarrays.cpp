//Back-end complete function Template for C++
class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // 2 pointer approach
        int i=0;
        int j=0;
        int n1 = a.size();
        int n2 = b.size();
        vector<int> intersect;
        while(i<n1 && j<n2){
            if (a[i] < b[j]) {
               i++;
        }
        else if (a[i] > b[j]) {
               j++;
        }
        else { // a[i] == b[j]
            if (intersect.empty() || intersect.back() != a[i]) {
                intersect.push_back(a[i]);
            }
            i++;
            j++;
        }

        }
        return intersect;
    }
};