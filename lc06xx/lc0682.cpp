//--- Q: 682. Baseball Game

//--- method 1: one pass
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> scores;
        int res = 0;
        for (auto op: ops) {
            if (op == "+") {
                scores.push_back(scores.back() + scores[scores.size()-2]);
            } else if (op == "D") {
                scores.push_back(scores.back()*2);
            } else if (op == "C") {
                res -= scores.back();
                scores.pop_back();
                continue;
            } else {
                scores.push_back(stoi(op));
            }
            res += scores.back();
        }
        return res;
    }
};