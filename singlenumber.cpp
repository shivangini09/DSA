#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;

        // O(nlogn)
        for (int num : nums) {
            freq[num]++;
        }

        // O(n/2+1)
        for (auto &p : freq) {
            if (p.second == 1) {
                return p.first;
            }
        }

        return -1; 
    }
};