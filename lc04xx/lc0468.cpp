//--- Q: 0468. Validate IP Address

//--- method 1: string parsing
class Solution {
public:
    # define INVALID "Neither"
    # define IPV4 "IPv4"
    # define IPV6 "IPv6"
    string validIPAddress(string IP) {
        int v4cnt = 0, v6cnt = 0, cnt = 0;
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
                if (str.size() > 1 && str[0] == '0' || str.size() > 3) {
                    return INVALID;
                }
                int sum = 0;
                for (auto &ch: str) {
                    if (!isdigit(ch)) {
                        return INVALID;
                    }
                    sum = sum*10 + ch-'0';
                }
                if (sum > 255) {
                    return INVALID;
                }
            }
            return cnt == 4 ? IPV4 : INVALID;
        } else if (v6cnt == 7) {
            while (ss >> str) {
                ++cnt;
                if (str.size() > 4) {
                    return INVALID;
                }
                for (auto &ch: str) {
                    if (!(isdigit(ch) || 'a' <= ch && ch <= 'f' || 'A' <= ch && ch <= 'F')) {
                        return INVALID;
                    }
                }
            }
            return cnt == 8 ? IPV6 : INVALID;
        } else {
            return INVALID;
        }
    }
};