class MyStack {
public:
    queue<int>inst;
    queue<int>out;
    MyStack() {
        
    }
    
    void push(int x) {
        inst.push(x);
        while(!out.empty()){
            inst.push(out.front());
            out.pop();
        }
        swap(inst,out);
    }
    
    int pop() {
        int a=out.front();
        out.pop();
        return a;
    }
    
    int top() {
        
        return out.front();
    }
    
    bool empty() {
        return out.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */