//--- Q: 1311. Get Watched Videos by Your Friends

//--- method 1: bfs + sort
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size(), l = -1;
        vector<int> visit(n, 0);
        vector<string> res;
        set<pair<int, string>> s;
        unordered_map<string, int> cnt;

        queue<int> que{{id}};
        visit[id] = 1;
        while (que.size() && ++l <= level) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                if (l == level) {
                    for (int j = 0; j < watchedVideos[now].size(); ++j) {
                        ++cnt[watchedVideos[now][j]];
                    }
                } else {
                    for (int j = 0; j < friends[now].size(); ++j) {
                        if (!visit[friends[now][j]]) {
                            visit[friends[now][j]] = 1;
                            que.push(friends[now][j]);
                        }
                    }
                }
            }
        }
        for (auto &p: cnt)
            s.insert({ p.second, p.first });
        for (auto &p: s)
            res.push_back(p.second);
        return res;
    }
};