class MyQueue {
public:
    stack<int>psh;
    stack<int>pp;
    MyQueue() {
        
    }
    
    void push(int x) {
        psh.push(x);
        
    }
    
    int pop() {
        while(!psh.empty()){
            pp.push(psh.top());
            psh.pop();
        }
        int a=pp.top();
        pp.pop();
        while(!pp.empty()){
            psh.push(pp.top());
            pp.pop();
        }
        return a;
    }
    
    int peek() {
        while(!psh.empty()){
            pp.push(psh.top());
            psh.pop();
        } int a=pp.top();
        while(!pp.empty()){
            psh.push(pp.top());
            pp.pop();
        }
       return a;
    }
    
    bool empty() {
        return psh.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */