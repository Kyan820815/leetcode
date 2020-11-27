//--- Q: 1189. Maximum Number of Balloons

//--- method 1: bucket sort
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnt(26, 0);
        for (int i = 0; i < text.size(); ++i) {
            ++cnt[text[i]-'a'];
        }
        int one = min(cnt['a'-'a'], min(cnt['b'-'a'], cnt['n'-'a']));
        int two = min(cnt['l'-'a'], cnt['o'-'a']);
        return min(one, two/2);
    }
};
