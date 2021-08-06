//--- Q: 0636. Exclusive Time of Functions

//--- method 1: stack operation
cclass Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> sk, res(n, 0);
        int lasttime;
        for (auto &log: logs) {
            int i, id = 0, time = 0;
            for (i = 0; log[i] != ':'; ++i) {
                id = id * 10 + log[i]-'0';
            }
            int start = 0;
            if (log[i+1] == 's') {
                start = 1;
                i += 7;
            } else {
                i += 5;
            }
            for (; i < log.size(); ++i) {
                time = time*10 + log[i]-'0';
            }
            if (start) {
                if (sk.size()) {
                    res[sk.back()] += time-lasttime;
                }
                sk.push_back(id);
                lasttime = time;
            } else {
                res[id] += time-lasttime+1;
                sk.pop_back();
                lasttime = time+1;
            }
        }
        return res;
    }
};