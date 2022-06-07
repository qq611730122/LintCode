//https://www.lintcode.com/problem/1850/description
//1850 ¡¤ ¼ñÆ»¹û
#include "LintCode.h"
/**
* @param a: a list of integer
* @param k: a integer
* @param l: a integer
* @return: return the maximum number of apples that they can collect.
*/

void process_dp1(const vector<int>& sum, int n, int m, vector<int>& dp);
void process_dp2(const vector<int>& sum, int n, int m, vector<int>& dp);

int pickApples(vector<int> &a, int k, int l)
{
	// write your code here
	int n = a.size();
	if (k + l > n)
	{
		return -1;
	}

	vector<int> sum(n);
	sum[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		sum[i] = sum[i - 1] + a[i];
	}

	vector<vector<int>> dp_k(2, vector<int>(n));
	vector<vector<int>> dp_l(2, vector<int>(n));

	process_dp1(sum, n, k, dp_k[0]);
	process_dp1(sum, n, l, dp_l[0]);

	process_dp2(sum, n, k, dp_k[1]);
	process_dp2(sum, n, l, dp_l[1]);

	int res = 0;
	for (int i = 0; i < n-1; i++)
	{
		res = max(res, dp_k[0][i] + dp_l[1][i+1]);
		res = max(res, dp_l[0][i] + dp_k[1][i+1]);
	}
	return res;
}

void process_dp1(const vector<int>& sum, int n, int m, vector<int>& dp)
{
	dp[m - 1] = sum[m - 1];

	for (int i = m; i < n; i++)
	{
		dp[i] = max(dp[i - 1], sum[i] - sum[i - m]);
	}
}

void process_dp2(const vector<int>& sum, int n, int m, vector<int>& dp)
{
	dp[n - m] = sum[n - 1] - sum[n - m - 1];
	for (int i = n - m - 1; i > 0; i--)
	{
		dp[i] = max(dp[i + 1], sum[i + m - 1] - sum[i - 1]);
	}
	dp[0] = max(dp[1], sum[m-1]);
}