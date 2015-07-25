/*
    可以用两个栈来模拟队列，s1用来存，s2用来取
    比较基础，详见代码
*/

class Queue {
private:
    stack<int> s1,s2;
public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(s2.size())   s2.pop();
        else{
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        if(s2.size())   return s2.top();
        else{
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }

    // Return whether the queue is empty.
    bool empty(void) {
        if(s1.size() || s2.size())  return false;
        return true;
    }
};

