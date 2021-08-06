//--- Q: 0692. Top K Frequent Words

//--- method 1: priority queue
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        auto comp = [&cnt](string &a, string &b) {
            return cnt[a] > cnt[b] || cnt[a] == cnt[b] && a < b;
        };
        priority_queue<string, vector<string>, decltype(comp)> que(comp);
        for (auto &word: words) {
            ++cnt[word];
        }
        for (auto &wd: cnt) {
            que.push(wd.first);
            if (que.size() > k) {
                que.pop();
            }
        }
        vector<string> res;
        while (que.size()) {
            res.push_back(que.top());
            que.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//--- method 2: bucket sort
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for (auto &word: words) {
            ++cnt[word];
        }
        vector<set<string>> bucket(words.size()+1);
        for (auto &wd: cnt) {
            bucket[wd.second].insert(wd.first);
        }
        vector<string> res;
        for (int i = words.size()-1; i >= 1 && k; --i) {
            for (auto it = bucket[i].begin(); it != bucket[i].end() && k; ++it, --k) {
                res.push_back(*it);
            }
        }
        return res;
    }
};