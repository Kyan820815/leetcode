//--- Q: 0506. Relative Ranks

//--- mehtod 1: sort then find index
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> idx;
        for (int i = 0; i < score.size(); ++i) {
            idx.push_back(i);
        }
        sort(idx.begin(), idx.end(), [&score](int i, int j){
            return score[i] > score[j];
        });
        vector<string> res(score.size());
        for (int i = 0; i < idx.size(); ++i) {
            if (!i) {
                res[idx[i]] = "Gold Medal";
            } else if (i == 1) {
                res[idx[i]] = "Silver Medal";
            } else if (i == 2) {
                res[idx[i]] = "Bronze Medal";
            } else {
                res[idx[i]] = to_string(i+1);
            }
        }
        return res;
    }
};