// Problem Link: https://leetcode.com/problems/min-stack/submissions/1689258184/
// Time Complexity: O(1) ~ for all operaions

class MinStack {
private:
    stack<int> st;
    stack<int> minStack;
public:

    void push(int val) {
        st.push(val);
        if(minStack.empty() || minStack.top() >= val) minStack.push(val);
    }

    void pop() {
        if (!st.empty()) {
            if (st.top() == minStack.top()) {
                minStack.pop();
            }
            st.pop();
        }
    }

    int top() {
        if (!st.empty()) return st.top();
        return -1;

    }

    int getMin() {
        if(!minStack.empty()) return minStack.top();
        return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */