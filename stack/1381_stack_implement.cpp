// Design a stack that supports increment operations on its elements.
// Implement the CustomStack class:

// CustomStack(int maxSize) Initializes the object with maxSize which 
// is the maximum number of elements in the stack.

// void push(int x) Adds x to the top of the stack if the stack has not reached the maxSize.

// int pop() Pops and returns the top of the stack or -1 if the stack is empty.

// void inc(int k, int val) Increments the bottom k elements of the stack by val.
//  If there are less than k elements in the stack, increment all the elements in the stack.


class CustomStack {
    int maxSize;
    int top;
    int *arr; 
public:
    CustomStack(int maxSize) {
        this->maxSize= maxSize;
        top=-1;
        arr = new int[maxSize];
    }
    
    void push(int x) {
        if(top!=(maxSize-1)){
            top++;
            arr[top]=x;
        }
    }
    
    int pop() {
        if(top>-1){
            int pop_element=arr[top];
            top--;
            return pop_element;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        for(int i =0; i<k; i++){
            if(i<=top){
                arr[i]+=val;
            }
            else{
                break;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */