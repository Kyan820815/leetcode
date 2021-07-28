//--- Q: 0451. Sort Characters By Frequency

//--- method 1: bucket sort
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        vector<vector<char>> bucket(s.size()+1);
        for (auto &ch: s) {
            ++cnt[ch];
        }
        for (auto &element: cnt) {
            if (element.second) {
                bucket[element.second].push_back(element.first);
            }
        }
        string res = "";
        for (int i = bucket.size()-1; i > 0; --i) {
            auto &vec = bucket[i];
            for (auto &ch: vec) {
                for (int j = 0; j < i; ++j) {
                    res += ch;
                }
            }
        }
        return res;
    }
};

//--- method 2: priority queue
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        auto comp = [&cnt](char a, char b) {
            return cnt[a] < cnt[b];
        };
        priority_queue<char, vector<char>, decltype(comp)> que(comp);
        for (auto &ch: s) {
            ++cnt[ch];
        }
        for (auto &element: cnt) {
            if (element.second) {
                que.push(element.first);
            }
        }
        string res = "";
        while (que.size()) {
            auto ch = que.top();
            que.pop();
            for (int i = 0; i < cnt[ch]; ++i) {
                res += ch;
            }
        }
        return res;
    }
};

//--- method 3: O(nlogn) built in sort
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        auto comp = [&cnt](char a, char b) {
            return cnt[a] > cnt[b] || cnt[a] == cnt[b] && a < b;
        };
        for (auto &ch: s) {
            ++cnt[ch];
        }
        sort(s.begin(), s.end(), comp);
        return s;
    }
};