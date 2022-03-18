//--- Q: 1823. Find the Winner of the Circular Game

//--- method 1: list simulation
class Solution {
public:
    int findTheWinner(int n, int k) {
        list<int> ll;
        for (int i = 1; i <= n; ++i) {
            ll.push_back(i);
        }
        auto iter = ll.begin();
        while (ll.size() > 1) {
            for (int i = 1; i < k; ++i) {
                if (next(iter) == ll.end()) {
                    iter = ll.begin();
                } else {
                    iter = next(iter);
                }
            }
            auto tmp = next(iter) == ll.end() ? ll.begin(): next(iter);
            ll.erase(iter);
            iter = tmp;
        }
        return ll.back();
    }
};

//--- method 2: array simulation
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> visit(n, 0);
        int cnt = n, i = 0;
        while (cnt > 1) {
            for (int j = 0; j < k;) {
                if (!visit[i]) {
                    ++j;
                }
                if (++i == n) {
                    i = 0;
                }
            }
            visit[((i-1)+n)%n] = 1;
            --cnt;
        }
        for (int i = 0; i < n; ++i) {
            if (!visit[i]) {
                return i+1;
            }
        }
        return -1;
    }
};

//--- method 3: bottom up simulation
class Solution {
public:
    int findTheWinner(int n, int k) {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            res = (res+k) % i;
        }
        return res+1;
    }
};
