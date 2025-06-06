class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) // pushing an element if it is +ve;
            {
                st.push(asteroids[i]);
            } 
            else {
                while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])) // asteroids smaller than our negatvie asteroid shud be popped bursted ofc
                {
                    st.pop();
                }
                if (!st.empty() && st.top() == abs(asteroids[i])){
                    st.pop(); // Destroy both asteroids
                } 
                else if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);   // push the aesteroiddd
                }
            }
        }

        // Convert stack to vector
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};