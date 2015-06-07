#include "GCD.h"

namespace utility
{
	namespace recursive
	{
		unsigned int GCD(unsigned int a, unsigned int b)
		{
			unsigned int uMax = a > b ? a : b;
			unsigned int uMin = a > b ? b : a;

			if (uMin == 0)
				return 0;	// Error input

			if (uMax % uMin == 0)
				return uMin;
			
			return GCD(uMin, uMax % uMin);
		}
	};
	
	namespace iterative
	{
		unsigned int GCD(unsigned int a, unsigned int b)
		{
			unsigned int uMax = a > b ? a : b;
			unsigned int uMin = a > b ? b : a;

			if (uMin == 0)
				return 0;	// Error input

			unsigned int uTemp = 0;
			while (uMax % uMin != 0)
			{
				uTemp = uMax;
				uMax = uMin;
				uMin = uTemp % uMin;
			}

			return uMin;
		}
	};
};