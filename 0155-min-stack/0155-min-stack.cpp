class MinStack {
public:
    stack<int> st;  // Main stack to hold elements
    stack<int> ss;  // Stack to hold minimum elements

    MinStack() {
    }

    void push(int val) {
        st.push(val);
        if (ss.empty() || val <= ss.top()) {
            ss.push(val);
        }
    }

    void pop() {
        if (!st.empty()) {
            if (st.top() == ss.top()) {
                ss.pop();
            }
            st.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        if(st.size()==0) return -1;
        return ss.top();
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