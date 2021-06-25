//--- Q: 692. Top K Frequent Words

//--- method 1: priority queue
class Solution {
public:
	static bool comp(pair<string,int> &a, pair<string,int> &b)
	{
		return (a.second > b.second) || (a.second == b.second && a.first < b. first);
	}
    vector<string> topKFrequent(vector<string>& words, int k) {
		unordered_map<string,int> appear;
		priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(&comp)> que(&comp);
		vector<string> res(k);
		int cnt = 0;
		for (int i = 0; i < words.size(); ++i)
			appear[words[i]]++;

		for (auto &a: appear)
		{
			if (que.size() < k)
				que.push({a.first, a.second});
			else
			{
				if (que.top().second < a.second || (que.top().second == a.second && a.first < que.top().first))
				{
					que.pop();
					que.push({a.first, a.second});
				}
			}
		}
		for (int i = k-1; i >= 0; --i)
		{
			res[i] = que.top().first;
			que.pop();
		}
		return res;
    }
};

//--- method 2: bucket sort
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
		unordered_map<string,int> appear;
		vector<string> res(k);
		vector<vector<string>> bucket(words.size()+1);
		int cnt = 0;
		for (int i = 0; i < words.size(); ++i)
			appear[words[i]]++;

		for (auto &a: appear)
			bucket[a.second].push_back(a.first);
		for (int i = bucket.size()-1; i >= 0; --i)
		{
			if (bucket[i].size() == 0) continue;
			sort(bucket[i].begin(), bucket[i].end());
			for (int j = 0; j < bucket[i].size() && cnt < k; ++j)
				res[cnt++] = bucket[i][j];
			if (cnt == k) break;
		}
		return res;
    }
};