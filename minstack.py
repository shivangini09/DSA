class MinStack {
private:
    std::stack<long long> st;
    long long mini;

public:
    // Constructor
    MinStack() : mini(LLONG_MAX) {}

    // Push an element onto the stack
    void push(int val) {
        if (st.empty()) {
            mini = val; // Initialize mini with the first value
            st.push(val);
        } else {
            if (val < mini) {
                // Push encoded value to indicate the new minimum
                st.push(2LL * val - mini);
                mini = val; // Update the minimum
            } else {
                st.push(val);
            }
        }
    }

    // Pop the top element
    void pop() {
        if (st.empty()) return;
        long long topValue = st.top();
        st.pop();
        if (topValue < mini) {
            // Retrieve the previous minimum
            mini = 2LL * mini - topValue;
        }
    }

    // Get the top element
    int top() {
        if (st.empty()) return -1;
        long long topValue = st.top();
        if (topValue < mini) {
            return mini; // If encoded, return the current minimum
        } else {
            return topValue; // Otherwise, return the actual value
        }
    }

    // Retrieve the minimum element
    int getMin() {
        return static_cast<int>(mini);
    }
};
