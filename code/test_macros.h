// test_macros.h: Macro companions to the test module.
// Include this in any test driver that uses test_.
// Macros cannot be exported from modules — this header bridges that gap.
// AUTHOR: Chuck Allison (Creative Commons License, 2001 - 2026)

#ifndef TEST_MACROS_H
#define TEST_MACROS_H

#define test_(cond) TestFramework::test(cond, #cond)
#define fail_(msg)  TestFramework::fail(msg)

#define throw_(expr, T)                                         \
    try {                                                       \
        expr;                                                   \
        TestFramework::fail("THROW expected: " #expr);          \
    } catch (const T&) {                                        \
        ++TestFramework::nPass;                                 \
    } catch (...) {                                             \
        TestFramework::fail("THROW wrong exception: " #expr);   \
    }

#define nothrow_(expr)                                          \
    try {                                                       \
        expr;                                                   \
        ++TestFramework::nPass;                                 \
    } catch (...) {                                             \
        TestFramework::fail("NOTHROW expected: " #expr);        \
    }

#define report_() TestFramework::report()

#endif
