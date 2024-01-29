#include <stack>

class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;

    MyQueue() {
    }

    void transferElements() {
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
    }

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        if (st2.empty()) {
            transferElements();
        }

        if (!st2.empty()) {
            int front = st2.top();
            st2.pop();
            return front;
        } else {
            return -1;
        }
    }

    int peek() {
        if (st2.empty()) {
            transferElements();
        }

        if (!st2.empty()) {
            return st2.top();
        } else {
            return -1;
        }
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
};

