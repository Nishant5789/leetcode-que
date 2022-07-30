class MyQueue {
    stack<int> st;
public:
    MyQueue() {
       
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop()
    {
        stack<int> temp;
        while(st.size()!=0)
        {
            temp.push(st.top());
            st.pop();
        }
        int x=temp.top();
        temp.pop();
        while(temp.size()!=0)
        {
            st.push(temp.top());
            temp.pop();
        }
        return x;
    }
    
    int peek() {
        stack<int> temp;
        while(st.size()!=0)
        {
            temp.push(st.top());
            st.pop();
        }
        int x=temp.top();
        while(temp.size()!=0)
        {
            st.push(temp.top());
            temp.pop();
        }
        return x; 
    }
    
    bool empty() {
        if(st.size()==0)
            return 1;
        return 0;
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