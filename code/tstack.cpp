// tstack.cpp: Test driver for Stack<T>
// C++23 module version.

import test;
import stack;
import std;
#include "test_macros.h"

int main() {
    Stack<int> stk;

    test_(stk.size() == 0);

    // Test exceptions (top and pop are invalid on empty stack)
    throw_(stk.top(), std::logic_error);
    throw_(stk.pop(), std::logic_error);
    nothrow_(stk.size());

    // Test push and top
    stk.push(1);
    test_(stk.top() == 1);
    test_(stk.size() == 1);
    stk.push(2);
    test_(stk.top() == 2);
    test_(stk.size() == 2);

    // Test pop
    stk.pop();
    test_(stk.top() == 1);
    test_(stk.size() == 1);
    stk.pop();
    test_(stk.size() == 0);
    throw_(stk.top(), std::logic_error);
    throw_(stk.pop(), std::logic_error);

    report_();
}
