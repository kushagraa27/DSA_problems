// problem: 155. Min Stack
// difficulty: medium
// topic: stack, design
// approach: for this problem, we made 2 stacks, one is normal stack having all values, other one is called minVal stack which store all min values at that time\
// suppose we popped a node from stack and that node is already the min value then it will be lost, we need to use the min val before that val, so we made a seperate
// stack for min val and if min val is popped we will pop it from min stack also and node under that val will be next min val, like this we will return min val from 
// min stack
// time: O(n)
// space: O(n)
// link: https://leetcode.com/problems/min-stack/description/

class MinStack {
    stack<int> st;
    stack<int> minVal;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(minVal.empty()||minVal.top()>=val)
        minVal.push(val);
        st.push(val);
    }
    
    void pop() {
        if(minVal.top()==st.top())
        minVal.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minVal.top();
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
