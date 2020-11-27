//--- Q: 636. Exclusive Time of Functions

//--- method 1: stack operation
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> sk;
        vector<int> res(n, 0);
        int lastTime = 0;
        for (int i = 0; i < logs.size(); ++i) {
            int idx1 = 0;
            while (logs[i][idx1++] != ':');
            int funcid = stoi(logs[i].substr(0, idx1-1));
            int idx2 = idx1;
            while (logs[i][idx2++] != ':');
            string type = logs[i].substr(idx1, idx2-idx1-1);
            int time = stoi(logs[i].substr(idx2));
            if (sk.size())
                res[sk.top()] += time - lastTime;
            lastTime = time;
            if (type == "start")
                sk.push(funcid);
            else {
                ++res[sk.top()];
                sk.pop();
                ++lastTime;
            }
        }
        return res;
    }
};