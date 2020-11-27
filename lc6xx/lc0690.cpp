//--- Q: 690. Employee Importance

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

//--- method 1: bfs
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> data;
        for (int i = 0; i < employees.size(); ++i) {
            data[employees[i]->id] = employees[i];
        }
        queue<int> que({id});
        int res = 0;
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto get = data[que.front()];
                que.pop();
                res += get->importance;
                for (int j = 0; j < get->subordinates.size(); ++j) {
                    que.push(get->subordinates[j]);
                }
            }
        }
        return res;        
    }
};