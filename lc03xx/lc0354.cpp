//--- Q: 0354. Russian Doll Envelopes

//--- method 1: lis
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0] || a[0] == b[0] && a[1] > b[1];
        });
        vector<vector<int>> res;
        for (auto &envelope:envelopes) {
            int left = 0, right = res.size()-1;
            while (left < right) {
                int mid = left + (right-left)/2;
                if (res[mid][0] < envelope[0] && res[mid][1] < envelope[1]) {
                    left = mid+1;
                } else {
                    right = mid;
                }
            }
            if (!res.size() || res[left][0] < envelope[0] && res[left][1] < envelope[1]) {
                res.push_back(envelope);
            } else {
                res[left] = envelope;
            }
        }
        return res.size();
    }
};
