class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        // Create a vector of pairs: (val/wt, index)
        vector<pair<double, int>> ratio;
        for (int i = 0; i < n; ++i) {
            double r = (double)val[i] / wt[i];
            ratio.push_back({r, i});
        }

        // Sort in descending order of value-to-weight ratio
        sort(ratio.begin(), ratio.end(), greater<>());

        double totalValue = 0.0;
        for (int i = 0; i < n && capacity > 0; ++i) {
            int idx = ratio[i].second;
            if (wt[idx] <= capacity) {
                totalValue += val[idx];
                capacity -= wt[idx];
            } else {
                totalValue += val[idx] * ((double)capacity / wt[idx]);
                break;
            }
        }

        return totalValue;
    }
};
