//--- Q: 1311. Get Watched Videos by Your Friends

//--- method 1: bfs + sort
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        unordered_map<string,int> map;
        unordered_set<int> visit;
        vector<pair<string,int>> vec;
        vector<string> res;
        queue<int> que;
        que.push(id);
        visit.insert(id);
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                if (!level) {
                    for (auto &video: watchedVideos[now]) {
                        if (map.find(video) == map.end()) {
                            map[video] = vec.size();
                            vec.push_back({video,1});
                        } else {
                            ++vec[map[video]].second;
                        }
                    }
                } else {
                    for (auto &next: friends[now]) {
                        if (visit.find(next) != visit.end()) {
                            continue;
                        }
                        visit.insert(next);
                        que.push(next);
                    }
                }
            }
            level--;
        }
        sort(vec.begin(), vec.end(), [](pair<string,int> &a, pair<string,int> &b){
            return a.second < b.second || a.second == b.second && a.first < b.first;
        });
        for (auto &node: vec) {
            res.push_back(node.first);
        }
        return res;
    }
};