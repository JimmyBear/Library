#include "Fibonacci.h"

namespace utility
{
	namespace recursive
	{
		unsigned int Fibonacci(unsigned int n)
		{
			if (n == 0)
				return 0;

			if (n == 1)
				return 1;

			return Fibonacci(n - 2) + Fibonacci(n - 1);
		}
	};
	
	namespace iterative
	{
		unsigned int Fibonacci(unsigned int n)
		{
			if (n == 0)
				return 0;

			if (n == 1)
				return 1;

			unsigned int uFib0 = 0;
			unsigned int uFib1 = 1;
			unsigned int uFibN = 0;

			unsigned int uIndex = 2;
			while (uIndex <= n)
			{
				uIndex++;

				uFibN = uFib0 + uFib1;
				uFib0 = uFib1;
				uFib1 = uFibN;
			}

			return uFibN;
		}
	};
};