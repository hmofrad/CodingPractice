/*
 * 	https://leetcode.com/problems/employee-importance/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// Definition for Employee.
class Employee {
public:
	Employee(){};
    int id;
    int importance;
    vector<int> subordinates;
};

std::unordered_map<int, int> id2importance;
std::unordered_map<int, std::vector<int>> id2subordinates;
int getImportance(int id) {
	int importance = id2importance[id];
	printf("%d %d\n", id, importance);
	for(int s: id2subordinates[id]) {
		importance += getImportance(s);
	}
	return importance;
}

int getImportance1(vector<Employee*> employees, int id) {
	for(Employee* employee: employees) {
		int id = employee->id;
		int importance = employee->importance;
		id2importance[id] = importance;
		std::vector<int>& subordinates = employee->subordinates;
		for(int s: subordinates) id2subordinates[id].push_back(s);
	}
	
	return getImportance(id);
}


int dfs(int id) {
	int imp=emps[id]->importance;
	for(int s: emps[id]->subordinates) imp+=dfs(s);
	return imp;
}

std::unordered_map<int, Employee*> emps;
int getImportance(vector<Employee*> employees, int id) {
	for(auto emp: employees) emps[emp->id]=emp;
	return dfs(id);
}

int main() {
	Employee* emp1 = new Employee(); emp1->id=1; emp1->importance=5; emp1->subordinates={2,3};
	Employee* emp2 = new Employee(); emp2->id=2; emp2->importance=3;
	Employee* emp3 = new Employee(); emp3->id=3; emp3->importance=3;
	std::vector<Employee*> emp = {emp1, emp2, emp3}; 
	//std::vector<std::vector<Employee*>> emp = {{1,5,{2,3}},{2,3,{}},{3,3,{}}};
	//int id = 1;
	int ret = getImportance(emp, 1);
	printf("Ret=%d\n", ret);
	return 1;
}