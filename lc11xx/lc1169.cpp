//--- Q: 1169. Invalid Transactions

//--- method 1: vector search
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<vector<string>> record;
        vector<string> res;
        unordered_set<int> set;
        for (int i = 0; i < n; ++i) {
            string tmp = "";
            vector<string> tmp_record;
            for (int j = 0; j <= transactions[i].size(); ++j) {
                if (j == transactions[i].size() || transactions[i][j] == ',') {
                    tmp_record.push_back(tmp);
                    tmp = "";
                } else {
                    tmp += transactions[i][j];
                }
            }
            if (stoi(tmp_record[2]) > 1000) {
                set.insert(i);
                res.push_back(transactions[i]);
            }
            record.push_back(tmp_record);
        }
        for (int i = 0; i < n; ++i) {
            if (set.find(i) != set.end()) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (record[i][0] != record[j][0]) {
                    continue;
                }
                if (record[i][3] != record[j][3] && abs(stoi(record[i][1])-stoi(record[j][1])) <= 60) {
                    if (set.find(i) == set.end()) {
                        set.insert(i);
                        res.push_back(transactions[i]);
                    }
                    if (set.find(j) == set.end()) {
                        set.insert(j);
                        res.push_back(transactions[j]);
                    }
                }
            }
        }
        return res;
    }
};