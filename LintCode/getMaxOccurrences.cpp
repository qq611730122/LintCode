//https://www.lintcode.com/problem/1824/description
//最频繁出现的子串

#include "LintCode.h"

/**
* @param s: string s
* @param minLength: min length for the substring
* @param maxLength: max length for the substring
* @param maxUnique: max unique letter allowed in the substring
* @return: the max occurrences of substring
*/
int getMaxOccurrences(string &str, int minLength, int maxLength, int maxUnique)
{
	// write your code here
	int n = str.size();
	unordered_map<string, int> subStr;
	unordered_map<char, int> hashMap;
	int i = 0;
	while (i < minLength)
	{
		++hashMap[str[i]];
		++i;
	}

	while (1)
	{
		if (hashMap.size() <= maxUnique)
		{
			++subStr[str.substr(i - minLength, minLength)];
		}

		if (i == n)
		{
			break;
		}

		++hashMap[str[i]];
		if (--hashMap[str[i - minLength]] == 0)
		{
			hashMap.erase(str[i - minLength]);
		}
		++i;
	}

	int res = 0;
	for (auto& p : subStr)
	{
		res = max(res, p.second);
	}
	return res;
}