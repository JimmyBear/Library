
#include "gtest/gtest.h"
#include "Fibonacci.h"

//------------------------------------------------------------------------------------------
// Fibonacci: 
// 0, 
// 1, 1, 2, 3, 5, 8, 13, 21, 34, 55,
// 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765

// The test case of recursive Fibonacci 
TEST(FibonacciTest, Recursive)
{
	using namespace utility::recursive;
	EXPECT_EQ(Fibonacci(40), 102334155);
}

// The test case of iterative Fibonacci
TEST(FibonacciTest, Iterative)
{
	using namespace utility::iterative;
	EXPECT_EQ(Fibonacci(40), 102334155);
}