//https://www.lintcode.com/problem/1492/
//1492 ¡¤ °®³ÔÏã½¶µÄçæçæ
#include "LintCode.h"

/**
* @param piles: an array
* @param h: an integer
* @return: the minimum integer K
*/
int minEatingSpeed(vector<int> &piles, int hours)
{
	// Write your code here
	int nMax = 0;
	int nMin = 1;
	for (int i : piles)
	{
		nMax = max(nMax, i);
	}

	int ret = 0;
	while (nMin <= nMax)
	{
		double m = nMin + (nMax - nMin >> 1);
		int h = 0;
		for (int i : piles)
		{
			h += std::ceil(i / m);
		}

		if (h <= hours)
		{
			ret = m;
			nMax = m - 1;
		}
		else
		{
			nMin = m + 1;
		}
	}
	return ret;
}