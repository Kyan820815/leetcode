//--- Q: 468. Validate IP Address

//--- method 1: string parsing
class Solution {
public:
    string validIPAddress(string IP) {
        int v4cnt = 0, v6cnt = 0, cnt = 0;
        string invalid = "Neither", v4 = "IPv4", v6 = "IPv6";
        for (auto &ch: IP) {
            if (ch == '.') {
                ch = ' ';
                ++v4cnt;
            } else if (ch == ':') {
                ch = ' ';
                ++v6cnt;
            }
        }
        istringstream ss(IP);
        string str;
        if (v4cnt == 3) {
            while (ss >> str) {
                ++cnt;
                if (!str.size() || str.size() > 3 || str[0] == '0' && str.size() > 1) {
                    return invalid;
                }
                int sum = 0;
                for (auto &ch: str) {
                    if (!isdigit(ch)) {
                        return invalid;
                    }
                    sum = sum * 10 + (ch-'0');
                }
                if (sum > 255) {
                    return invalid;
                }
            }
            return cnt == 4 ? v4 : invalid;
        } else if (v6cnt == 7) {
            while (ss >> str) {
                ++cnt;
                if (!str.size() || str.size() > 4) {
                    return invalid;
                }
                for (auto &ch: str) {
                    if (!(isdigit(ch) || 'a' <= ch && ch <= 'f' || 'A' <= ch && ch <= 'F')) {
                        return invalid;
                    }
                }
            }
            return cnt == 8 ? v6 : invalid;
        }
        return invalid;
    }
};