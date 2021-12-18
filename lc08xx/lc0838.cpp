//--- Q: 0838. Push Dominoes

//--- method 1: in place linear time
class Solution {
public:
    string pushDominoes(string dominoes) {
        int last = -1;
        for (int i = 0; i < dominoes.size(); ++i) {
            if (dominoes[i] == '.') {
                if (last != -1 && dominoes[last] == 'R') {
                    dominoes[i] = 'R';
                }
            } else {
                if (dominoes[i] == 'L') {
                    int start;
                    if (last != -1 && dominoes[last] == 'R') {
                        int mid = last+(i-last)/2;
                        if (!((last+i)&1)) {
                            dominoes[mid] = '.';
                        }
                        start = mid+1;
                    } else {
                        start = last+1;
                    }
                    for (int j = start; j < i; ++j) {
                        dominoes[j] = 'L';
                    }
                }
                last = i;
            }
        }
        return dominoes;
    }
};