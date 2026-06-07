// test.cppm: Simple but effective automated test scaffolding
// C++23 module version using import std and std::source_location.
// Macros live in companion header test_macros.h (modules cannot export macros).
// AUTHOR: Chuck Allison (Creative Commons License, 2001 - 2026)

export module test;

import std;

export namespace TestFramework {
    inline std::size_t nPass = 0;
    inline std::size_t nFail = 0;

    inline void fail(
        std::string_view msg,
        const std::source_location& loc = std::source_location::current())
    {
        std::cout << "FAILURE: " << msg
                  << " in file " << loc.file_name()
                  << " on line " << loc.line()
                  << " in function " << loc.function_name() << '\n';
        ++nFail;
    }

    inline void test(
        bool cond,
        std::string_view expr,
        const std::source_location& loc = std::source_location::current())
    {
        if (cond)
            ++nPass;
        else
            fail(expr, loc);
    }

    inline void succeed() {
        ++nPass;
    }

    inline void report() {
        std::cout << "\nTest Report:\n\n"
                  << "\tNumber of Passes = " << nPass << '\n'
                  << "\tNumber of Failures = " << nFail << '\n';
    }
}
