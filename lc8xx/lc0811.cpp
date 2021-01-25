//--- Q: 811. Subdomain Visit Count

//--- method 1: map operation
class Solution {
public:
    unordered_map<string, int> map;
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        for (int i = 0; i < cpdomains.size(); ++i) {
            int idx = 0, sum = 0;
            while (cpdomains[i][idx] != ' ') {
                sum = sum * 10 + cpdomains[i][idx++]-'0';
            }
            ++idx;
            string address = cpdomains[i].substr(idx);
            compute(address, sum);
        }
        vector<string> res;
        for (auto &s: map) {
            res.push_back(to_string(s.second) + " " + s.first);
        }
        return res;
    }
    void compute(string &address, int times) {
        string add = "";
        for (int i = address.size()-1; i >= 0; --i) {
            if (address[i] == '.') {
                map[add] += times;
            }
            add = address[i] + add;
        }
        map[add] += times;
    }
};
