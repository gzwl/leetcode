/*
    用两个队列来模拟栈，我们可以用q[0]来装入元素，q[1]来存储栈顶元素
*/

class Stack {
private:
    queue<int> q[2];
public:
    // Push element x onto stack.
    void push(int x) {
        if(q[1].empty())    q[1].push(x);
        else{
            q[0].push(q[1].front());
            q[1].pop();
            q[1].push(x);
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        if(q[1].size())     q[1].pop();
        else{
            while(q[0].size() != 1){
                q[1].push(q[0].front());
                q[0].pop();
            }
            q[0].pop();
            while(q[1].size() != 1 && q[1].size() != 0){
                q[0].push(q[1].front());
                q[1].pop();
            }
        }
    }

    // Get the top element.
    int top() {
        if(q[1].size())     return q[1].front();
        else{
            while(q[0].size()){
                q[1].push(q[0].front());
                q[0].pop();
            }
            while(q[1].size() != 1){
                q[0].push(q[1].front());
                q[1].pop();
            }
            return q[1].front();
        }
    }

    // Return whether the stack is empty.
    bool empty() {
        return q[0].empty() && q[1].empty();
    }
};

