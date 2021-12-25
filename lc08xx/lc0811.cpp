//--- Q: 0811. Subdomain Visit Count

//--- method 1: map operation
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> map;
        for (auto &cpdomain: cpdomains) {
            int i, times = 0;
            for (i = 0; cpdomain[i] != ' '; ++i) {
                times = times*10 + (cpdomain[i]-'0');
            }
            for (; i < cpdomain.size(); ++i) {
                if (cpdomain[i] == ' ' || cpdomain[i] == '.') {
                    map[cpdomain.substr(i+1)] += times;
                }
            }
        }
        vector<string> res;
        for (auto &pkg: map) {
            res.push_back(to_string(pkg.second) + " " + pkg.first);
        }
        return res;
    }
};