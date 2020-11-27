//--- Q: 1086. High Five

//--- method 1: counting sort
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> score, res;
        for (int i = 0; i < items.size(); ++i) {
            if (score.size() < items[i][0])
                score.resize(items[i][0], vector<int>(101, 0));
            ++score[items[i][0]-1][items[i][1]];
        }
        for (int i = 0; i < score.size(); ++i) {
            int sum = 0;
            for (int j = 100, c = 5; c > 0 && j > 0; --j) {
                if (score[i][j]) {
                    int t = min(c, score[i][j]);
                    sum += (j*t);
                    c -= t;
                }
            }
            res.push_back({i+1, sum/5});
        }
        return res;
    }
};

//--- method 2: partial sort
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> score, res;
        for (int i = 0; i < items.size(); ++i) {
            if (score.size() < items[i][0])
                score.resize(items[i][0]);
            score[items[i][0]-1].push_back(items[i][1]);
        }
        for (int i = 0; i < score.size(); ++i) {
            partial_sort(score[i].begin(), score[i].begin()+5, score[i].end(), greater<int>());
            int avg = (score[i][0] + score[i][1] + score[i][2] + score[i][3] + score[i][4]) / 5;
            res.push_back({i+1, avg});
        }
        return res;
    }
};