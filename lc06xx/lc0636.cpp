//--- Q: 636. Exclusive Time of Functions

//--- method 1: stack operation
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> sk;
        vector<int> res(n, 0);
        int last_time = 0;
        for (int i = 0; i < logs.size(); ++i) {
            int idx = 0, id = 0, time = 0;
            string log = logs[i];
            while (log[idx] != ':') {
                id = id * 10 + log[idx++]-'0';
            }
            ++idx;
            if (log[idx] == 's') {
                time = stoi(log.substr(idx+6));
                if (sk.size()) {
                    res[sk.back()] += time-last_time;
                }
                sk.push_back(id);
                last_time = time;
            } else {
                time = stoi(log.substr(idx+4));
                res[id] += time-last_time+1;
                sk.pop_back();
                last_time = time+1;
            }
        }
        return res;
    }
};