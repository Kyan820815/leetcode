//--- Q: 1361. Validate Binary Tree Nodes

//--- method 1: bfs
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        if (leftChild.size() != rightChild.size()) {
            return false;
        }
        vector<int> deg(n, 0);
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                ++deg[leftChild[i]];
            }
            if (rightChild[i] != -1) {
                ++deg[rightChild[i]];
            }
        }
        queue<int> que;
        for (int i = 0; i < n; ++i) {
            if (!deg[i]) {
                que.push(i);
            } else if (deg[i] > 1) {
                return false;
            }
        }
        if (que.size() > 1) {
            return false;
        }
        while (que.size()) {
            auto qsize = que.size();
            n -= qsize;
            while (qsize--) {
                auto now = que.front();
                que.pop();
                if (leftChild[now] != -1 && !--deg[leftChild[now]]) {
                    que.push(leftChild[now]);
                }
                if (rightChild[now] != -1 && !--deg[rightChild[now]]) {
                    que.push(rightChild[now]);
                }
            }
        }
        return !n;
    }
};

//--- method 2: dfs
class Solution {
public:
    vector<int> visit;
    int cnt = 0;
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        if (leftChild.size() != rightChild.size()) {
            return false;
        }
        vector<int> deg(n, 0);
        visit.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                ++deg[leftChild[i]];
            }
            if (rightChild[i] != -1) {
                ++deg[rightChild[i]];
            }
        }
        int startcnt = 0, start;
        for (int i = 0; i < n; ++i) {
            if (!deg[i]) {
                ++startcnt;
                start = i;
            }
        }
        if (startcnt != 1) {
            return false;
        }
        return dfs(start, leftChild, rightChild) && cnt == n;
    }
    int dfs(int now, vector<int> &left, vector<int> &right) {
        if (visit[now]) {
            return 0;
        }
        ++cnt;
        visit[now] = 1;
        if (left[now] != -1 && !dfs(left[now], left, right)) {
            return false;
        }
        if (right[now] != -1 && !dfs(right[now], left, right)) {
            return false;
        }
        return 1;
    }
};
