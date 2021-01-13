//--- Q: 792. Number of Matching Subsequences

//--- method 1: two pointer and hashmap
class Solution {
public:
	int numMatchingSubseq(string S, vector<string>& words) {
		int res = 0;
		unordered_map<string, int> map;
		for (int i = 0; i < words.size(); ++i)
			++map[words[i]];
		for (auto &m: map) {
			int left = 0, idx = 0;
			while (left < S.size()) {
				if (S[left] == m.first[idx])
				   ++idx;
				if (idx == m.first.size())
					break;
				++left;
			}
			if (idx == m.first.size())
				res += m.second;
		}
		return res;
	}
};

//--- method 2: character operation with length processing
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<pair<int, int>>> word_list(26);
        int res = 0;
        for (int i = 0; i < words.size(); ++i) {
            word_list[words[i][0]-'a'].push_back({i, 0});
        }
        for (int i = 0; i < S.size(); ++i) {
            auto tmp = word_list[S[i]-'a'];
            word_list[S[i]-'a'].clear();
            for (int j = 0; j < tmp.size(); ++j) {
                if (tmp[j].second+1 == words[tmp[j].first].size()) {
                    ++res;
                } else {
                    word_list[words[tmp[j].first][tmp[j].second+1]-'a'].push_back({tmp[j].first, tmp[j].second+1});
                }
            }
        }
        return res;
    }
};