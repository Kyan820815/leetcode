//--- Q: 838. Push Dominoes

//--- method 1: in place linear time
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size(), idx, last = -1;
        for (int i = last+1; i < n; ++i) {
            if (dominoes[i] == '.') {
                if (last >= 0 && dominoes[last] == 'R') {
                    dominoes[i] = 'R';
                }
                continue;
            } else if (dominoes[i] == 'L' && i-last > 1) {
                int end = last;
                if (last >= 0 && dominoes[last] == 'R') {
                    end = (last+i)/2;
                    if ((last+i) % 2 == 0) {
                        dominoes[end] = '.';
                    }
                }
                for (int j = i-1; j > end; --j) {
                    dominoes[j] = 'L';
                }
            }
            last = i;
        }
        return dominoes;
    }
};

//--- method 2: two pointer
class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = "L" + dominoes + "R";
        int left = 0, right = 1;
        string res = "";
        while (right < dominoes.size()) {
            if (dominoes[right] == '.') {
                ++right;
                continue;
            }
            int midlen = right-left-1;
            if (midlen) {
                if (dominoes[left] == dominoes[right]) {
                    res += string(midlen, dominoes[left]);
                } else if (dominoes[left] == 'R' && dominoes[right] == 'L') {
                    res += string(midlen/2, 'R') + string(midlen%2, '.') + string(midlen/2, 'L');
                } else if (dominoes[right] == 'R' && dominoes[left] == 'L') {
                    res += string(midlen, '.');
                }
            }
            res += dominoes[right];
            left = right++;
        }
        res.pop_back();
        return res;
    }
};