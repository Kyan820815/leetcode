//--- Q: 0690. Employee Importance

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
        unordered_map<int, Employee *> map;
        for (auto &employee: employees) {
            map[employee->id] = employee;
        }
        queue<int> que;
        que.push(id);
        int res = 0;
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = map[que.front()];
                que.pop();
                res += now->importance;
                for (auto &sub: now->subordinates) {
                    que.push(sub);
                }
            }
        }
        return res;
    }
};