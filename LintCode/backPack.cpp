//https://www.lintcode.com/problem/92/
//92 °§ ±≥∞¸Œ Ã‚
#include "LintCode.h"
/**
* @param m: An integer m denotes the size of a backpack
* @param a: Given n items with size A[i]
* @return: The maximum size
*/
int recursive(int m, const vector<int>& a, int i)
{
	if (m <= 0 || i == a.size())
	{
		return 0;
	}

	if (a[i] > m)
	{
		return recursive(m, a, i + 1);
	}
	else
	{
		return max(a[i] + recursive(m - a[i], a, i + 1), recursive(m, a, i + 1));
	}
}

int backPack(int m, vector<int> &a)
{
	// write your code here
	//return recursive(m, a, 0);
	int n = a.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i] > j)
			{
				dp[i][j] = dp[i + 1][j];
			}
			else
			{
				dp[i][j] = max(a[i] + dp[i + 1][j - a[i]], dp[i + 1][j]);
			}
		}
	}
	return dp[0][m];
}