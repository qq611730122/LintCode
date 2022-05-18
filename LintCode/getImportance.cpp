//https://www.lintcode.com/problem/1082/
//1082 · 员工的重要度
#include "LintCode.h"

class Employee
{
public:
	// It's the unique ID of each node.
	// unique id of this employee
	int id;
	// the importance value of this employee
	int importance;
	// the id of direct subordinates
	vector<int> subordinates;
};

int getImportance(vector<Employee*> employees, int id)
{
	// Write your code here.
	unordered_map<int, Employee*> hashMap;
	for (Employee* employee : employees)
	{
		hashMap[employee->id] = employee;
	}
	
	if (hashMap.count(id) == 0)
	{
		return 0;
	}
	queue<Employee*> que;	
	que.push(hashMap[id]);
	int res = 0;
	while (!que.empty())
	{
		Employee* pEmp = que.front();
		que.pop();
		res += pEmp->importance;
		for (int id : pEmp->subordinates)
		{
			que.push(hashMap[id]);
		}
	}
	return res;
}