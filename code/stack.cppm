// stack.cppm: A simple stack with exceptions
// C++23 module version.

export module stack;

import std;

export template<typename T>
class Stack {
    std::stack<T> data;
public:
    T& top() {
        if (data.empty())
            throw std::logic_error("underflow");
        return data.top();
    }
    const T& top() const {
        if (data.empty())
            throw std::logic_error("underflow");
        return data.top();
    }
    void push(const T& t) {
        data.push(t);
    }
    void pop() {
        if (data.empty())
            throw std::logic_error("underflow");
        data.pop();
    }
    std::size_t size() const {
        return data.size();
    }
};
