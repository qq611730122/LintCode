//https://www.lintcode.com/problem/2506/
//2506 ¡¤ É¾³ı²»Æ¥ÅäµÄÀ¨ºÅ
#include "LintCode.h"
/**
* @param s: A string with lowercase letters and parentheses
* @return: A string which has been removed invalid parentheses
*/
string removeParentheses(string &s)
{
	// write your code here.
	auto p = s.begin();
	auto end = s.end();
	int cnt = 0;
	while (p != end)
	{
		if (*p == '(')
		{
			++cnt;
		}
		else if (*p == ')')
		{
			if (cnt == 0)
			{
				p = s.erase(p);
				continue;
			}
			else
			{
				--cnt;
			}
		}
		++p;
	}

	while (cnt > 0)
	{
		if (*p == '(')
		{
			p = s.erase(p);
			--cnt;
		}
		--p;
	}
	return s;
}