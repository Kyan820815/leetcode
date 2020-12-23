//--- Q: 1583. Count Unhappy Friends

//--- method 1:  O(n^2)
class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int res = 0;
        vector<int> map(n);
        vector<vector<int>> pref(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < pairs.size(); ++i) {
            map[pairs[i][0]] = pairs[i][1];
            map[pairs[i][1]] = pairs[i][0];
        }
        for (int i = 0; i < preferences.size(); ++i) {
            for (int j = 0; j < preferences[i].size(); ++j) {
                pref[i][preferences[i][j]] = j;
            }
        }
        for (int i = 0; i < n; ++i) {
            int self = i, partner = map[i];
            for (int i = 0; i < preferences[self].size(); ++i) {
                if (preferences[self][i] == partner) {
                    break;
                }
                int other = preferences[self][i];
                if (pref[self][partner] > pref[self][other] && pref[other][self] < pref[other][map[other]]) {
                    ++res;
                    break;
                }
            }
        }
        return res;
    }
};

//--- method 2: O(n^3)
class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int res = 0;
        vector<int> map(n);
        for (int i = 0; i < pairs.size(); ++i) {
            map[pairs[i][0]] = pairs[i][1];
            map[pairs[i][1]] = pairs[i][0];
        }
        for (int i = 0; i < n; ++i) {
            int self = i, partner = map[i];
            for (int i = 0; i < preferences[self].size(); ++i) {
                if (preferences[self][i] == partner) {
                    break;
                }
                bool unhappy = false;
                int other = preferences[self][i];
                for (int j = 0; j < preferences[other].size(); ++j) {
                    if (preferences[other][j] == self) {
                        unhappy = true;
                        break;
                    } else if (preferences[other][j] == map[other]){
                        break;
                    }
                }
                if (unhappy) {
                    ++res;
                    break;
                }
            }
        }
        return res;
    }
};