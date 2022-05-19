//https://www.lintcode.com/problem/4/
//³óÊý II
#include "LintCode.h"
/**
* @param n: An integer
* @return: return a  integer as description.
*/
int nthUglyNumber(int n){
	// write your code here
	vector<int> dp(n);
	dp[0] = 1;
	int idx2 = 0, idx3 = 0, idx5 = 0;
	for (int i = 1; i < n; i++)
	{
		int tmp2 = dp[idx2] * 2;
		int tmp3 = dp[idx3] * 3;
		int tmp5 = dp[idx5] * 5;
		dp[i] = min({ tmp2 , tmp3 , tmp5});
		if (tmp2 == dp[i])
			++idx2;
		if (tmp3 == dp[i])
			++idx3;
		if (tmp5 == dp[i])
			++idx5;
	}
	return dp[n - 1];
}

