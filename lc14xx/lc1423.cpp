//--- Q: 1423. Maximum Points You Can Obtain from Cards

//--- method 1: sliding window O(n)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total, window = 0, n = cardPoints.size(), minv;
        for (int i = 0; i < n-k; ++i) {
            window += cardPoints[i];
        }
        minv = total = window;
        for (int i = n-k; i < n; ++i) {
            total += cardPoints[i];
            window += cardPoints[i];
            window -= cardPoints[i-(n-k)];
            minv = min(minv, window);
        }
        return total-minv;
    }
};

//--- method 2: sliding window O(k)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left = 0, right = 0, n = cardPoints.size();
        for (int i = 0; i < k; ++i) {
            left += cardPoints[i];
        }
        int res = left;
        for (int i = 0; i < k; ++i) {
            left -= cardPoints[k-1-i];
            right += cardPoints[n-1-i];
            res = max(res, left+right);
        }
        return res;
    }
};