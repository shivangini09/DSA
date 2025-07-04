class MyStack {
private:
    queue<int> q;
public:

    MyStack() {
        // queue<int> q;
    }
    
    void push(int x) {
        int size = q.size();
        q.push(x);
        for(int i=0; i<size; i++){
            q.push(q.front());
            q.pop();
        }
        
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.empty()){
            return true;
        }
        return false;
    }
};
