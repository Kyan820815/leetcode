//--- Q: 0682. Baseball Game

//--- method 1: one pass
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int res = 0;
        vector<int> sk;
        for (auto &op: ops) {
            if (op == "+") {
                auto n = sk.size();
                sk.push_back(sk[n-1]+sk[n-2]);
            } else if (op == "D") {
                sk.push_back(sk.back()*2);
            } else if (op == "C") {
                res -= sk.back();
                sk.pop_back();
                continue;
            } else {
                sk.push_back(stoi(op));
            }
            res += sk.back();
        }
        return res;
    }
};