//--- Q: 1169. Invalid Transactions

//--- method 1: vector search
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> name, time, money, place, res;
        vector<int> invalid(transactions.size(), 0);
        for (int i = 0; i < transactions.size(); ++i) {
            vector<string> tmp;
            string str = "";
            for (int j = 0; j <= transactions[i].size(); ++j) {
                if (j == transactions[i].size() || transactions[i][j] == ',') {
                    tmp.push_back(str);
                    str = "";
                } else {
                    str.push_back(transactions[i][j]);
                }
            }
            name.push_back(tmp[0]);
            time.push_back(tmp[1]);
            money.push_back(tmp[2]);
            place.push_back(tmp[3]);
        }
        for (int i = 0; i < transactions.size(); ++i) {
            if (stoi(money[i]) > 1000) {
                invalid[i] = 1;
            }
            for (int j = i+1; j < transactions.size(); ++j) {
                if (name[i] == name[j] && place[i] != place[j] && abs(stoi(time[i])-stoi(time[j])) <= 60) {
                    invalid[i] = invalid[j] = 1;
                }
            }
        }
        for (int i = 0; i < invalid.size(); ++i) {
            if (invalid[i]) {
                res.push_back(transactions[i]);
            }
        }
        return res;
    }
};