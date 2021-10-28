//--- Q: 0726. Number of Atoms

//--- method 1: map and recursion
class Solution {
public:
    string countOfAtoms(string formula) {
        int idx = 0;
        auto count = dfs(idx, formula);
        string res = "";
        for (auto &atom: count) {
            res += atom.first;
            if (atom.second > 1) {
                res += to_string(atom.second);
            }
        }
        return res;
    }
    map<string, int> dfs(int &idx, string &formula) {
        map<string, int> count;
        string atom = "";
        while (idx < formula.size()) {
            if (formula[idx] == '(') {
                ++idx;
                auto rtn_count = dfs(idx, formula);
                for (auto &at: rtn_count) {
                    count[at.first] += at.second;
                }
            } else if (formula[idx] == ')') {
                ++idx;
                int times = 0;
                while (idx < formula.size() && isdigit(formula[idx])) {
                    times = times*10 + formula[idx++]-'0';
                }
                times = !times ? 1 : times;
                for (auto &at: count) {
                    at.second *= times;
                }
                return count;
            } else {
                atom += formula[idx++];
                while (idx < formula.size() && islower(formula[idx])) {
                    atom += formula[idx++];
                }
                int times = 0;
                while (idx < formula.size() && isdigit(formula[idx])) {
                    times = times*10 + formula[idx++]-'0';
                }
                count[atom] += !times ? 1 : times;
                atom = "";
            }
        }
        return count;
    }
};

//--- method 2: stack
class Solution {
public:
    string countOfAtoms(string formula) {
        vector<map<string,int>> sk;
        int idx = 0;
        string atom = "";
        map<string,int> count;
        while (idx < formula.size()) {
            if (formula[idx] == '(') {
                ++idx;
                sk.push_back(count);
                count.clear();
            } else if (formula[idx] == ')') {
                ++idx;
                int times = 0;
                while (idx < formula.size() && isdigit(formula[idx])) {
                    times = times*10 + formula[idx++]-'0';
                }
                times = !times ? 1 : times;
                for (auto &at: count) {
                    at.second *= times;
                }
                auto last = sk.back();
                sk.pop_back();
                for (auto &atom: count) {
                    last[atom.first] += atom.second;
                }
                count = last;
            } else {
                atom += formula[idx++];
                while (idx < formula.size() && islower(formula[idx])) {
                    atom += formula[idx++];
                }
                int times = 0;
                while (idx < formula.size() && isdigit(formula[idx])) {
                    times = times*10 + formula[idx++]-'0';
                }
                count[atom] += !times ? 1 : times;
                atom = "";
            }
        }
        string res = "";
        for (auto &atom: count) {
            res += atom.first;
            if (atom.second > 1) {
                res += to_string(atom.second);
            }
        }
        return res;
    }
};