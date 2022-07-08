//https://www.lintcode.com/problem/13/
//13 ¡¤ ×Ö·û´®²éÕÒ
#include "LintCode.h"

vector<int> getNext(const string& str)
{
	int n = str.size();
	if (n == 0)
	{
		return vector<int>();
	}

	vector<int> next(n);
	next[0] = -1;
	if (n > 1)
		next[1] = 0;
	for (int i = 2; i<n; i++)
	{
		int j = next[i - 1];
		while (j > 0 && str[i - 1] != str[j])
		{
			j = next[j];
		}
		next[i] = j + 1;
	}
	return next;
}

/**
* @param source:
* @param target:
* @return: return the index
*/
int strStr(string &source, string &target)
{
	// Write your code here
	int m = source.size();
	int n = target.size();
	if (n > m)
	{
		return -1;
	}

	vector<int> next = getNext(target);

	int i = 0;
	int j = 0;
	while (i < m && j < n)
	{
		if (source[i] == target[j])
		{
			i++;
			j++;
		}
		else if (j == 0)
		{
			i++;
		}
		else
		{
			j = next[j];
		}
	}

	return j == n ? i - j : -1;
}