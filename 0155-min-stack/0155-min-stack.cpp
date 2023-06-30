class MinStack {
public:
    stack<int>st;
    int mini=INT_MAX;
    vector<int>v;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(val<=mini){mini=val;
        v.push_back(mini);}
    }
    
    void pop() {
        if (st.top() == mini) {
            v.pop_back();
            if (!v.empty()) {
                int n = v.size();
                mini = v[n - 1];
            } else {
                mini = INT_MAX;
            }
        }
        st.pop();

    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini;
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