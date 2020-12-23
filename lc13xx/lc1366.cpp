//--- Q: 1366. Rank Teams by Votes

//--- method 1: count votes and self-defined lamda function
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int team = votes[0].size();
        vector<vector<int>> map(26);
        string res = "";
        for (int i = 0; i < votes.size(); ++i) {
            for (int j = 0; j < votes[i].size(); ++j) {
                if (!map[votes[i][j]-'A'].size()) {
                    map[votes[i][j]-'A'].resize(team, 0);
                    res.push_back(votes[i][j]);
                }
                ++map[votes[i][j]-'A'][j];
            }
        }
        sort(res.begin(), res.end(), [&map, &team](char a, char b) {
            for (int i = 0; i < team; ++i)  {
                if (map[a-'A'][i] == map[b-'A'][i]) {
                    continue;
                }
                return map[a-'A'][i] > map[b-'A'][i];
            }
            return a < b;
        });
        return res;
    }
};