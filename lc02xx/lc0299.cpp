//--- Q: 0299. Bulls and Cows

//--- method 1: one pass find current digit positive or negative
class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> cnt(10, 0);
        int n = secret.size(), bull = 0, cow = 0;
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) {
                ++bull;
            } else {
                cow += cnt[secret[i]-'0'] > 0;
                cow += cnt[guess[i]-'0'] < 0;
                --cnt[secret[i]-'0'];
                ++cnt[guess[i]-'0'];
            }
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};

//--- method 2: two pass find share character
class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> scnt(10, 0), gcnt(10, 0);
        int a = 0, total = 0, cnt;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                ++a;
            }
            ++scnt[secret[i]-'0'];
            ++gcnt[guess[i]-'0'];
        }
        for (int i = 0; i < 10; ++i) {
            if ((cnt = min(scnt[i],gcnt[i])) > 0) {
                total += cnt;
            }
        }
        return to_string(a) + "A" + to_string(total-a) + "B";
    }
};
