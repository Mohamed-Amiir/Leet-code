class MinStack {
    vector<int> arr;
    vector<int> mini;
    int size = 0;

    int m=1e9;
public:
    MinStack() {
        this->size = size;
    }
    
    void push(int val) {
        arr.push_back(val);
        size++;
        if(mini.empty() || mini.back() >= val)
           mini.push_back(val);
       
    }
    
    void pop() {
        if(size == 0)
           cout << "You can not pop from empty stack";
        else{
            if(arr.back() == mini.back())
                mini.pop_back();
           arr.pop_back();
           size--;
        }
           
    }
    
    int top() {
        return arr.back();
    }
    
    int getMin() {
        return mini.back();
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