class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> nge(n, -1);
        stack<int> st;

        // Step 1: Find NGE for all elements in nums2
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && st.top() <= nums2[i]) st.pop();
            if (!st.empty()) nge[i] = st.top();
            st.push(nums2[i]);
        }

        // Step 2: For each element in nums1, find its index in nums2
        vector<int> result;
        for (int num : nums1) {
            for (int i = 0; i < n; ++i) {
                if (nums2[i] == num) {
                    result.push_back(nge[i]);
                    break;
                }
            }
        }

        return result;
    }
};
