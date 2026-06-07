# test-framework
A C++23 version of the sequel to my old <a href="https://freshsources.com/articles/CUJ/1809/allison1.htm">The Simplest Automated Unit Test Framework That Could Possibly Work</a>. 

That sequel can be found <a href="https://freshsources.com/articles/academic/55_Lines.pdf">here</a>.

What was in a single header file is now spread across two files:

1) test.cppm (the C++23 module)
2) test_macros.h (some things still require the preprocessor)

The other code files stack.cppm, and tstack.cpp, constitute a simple stack class for illustrating how to use the test framework.
