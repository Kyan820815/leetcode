//--- Q: 0929. Unique Email Addresses

//--- method 1: string processing
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> set;
        for (auto &email: emails) {
            int idx = email.find('@');
            string domain = email.substr(idx);
            string local = "";
            for (int i = 0; i < email.size(); ++i) {
                if (email[i] == '@' || email[i] == '+') {
                    set.insert(local+domain);
                    break;
                } else if (email[i] != '.') {
                    local += email[i];
                }
            }
        }
        return set.size();
    }
};