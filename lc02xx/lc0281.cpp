//--- Q: 0281. Zigzag Iterator

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

//--- method 1: index recording
class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        arr.push_back(v1);
        arr.push_back(v2);
        idx.resize(arr.size(), 0);
        i = 0;
    }

    int next() {
        int val = arr[i][idx[i]++];
        i = (i+1)%arr.size();
        return val;
    }

    bool hasNext() {
        int cnt = 0;
        while (idx[i] == arr[i].size()) {
            i = (i+1)%arr.size();
            if (++cnt == arr.size()) {
                break;
            }
        }
        return cnt < arr.size();
    }
    vector<int> idx;
    int i;
    vector<vector<int>> arr;
};

//--- method 2: iterator recording
class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.size()) {
            que.push({v1.begin(), v1.end()});
        }
        if (v2.size()) {
            que.push({v2.begin(), v2.end()});
        }
    }

    int next() {
        auto idx = que.front();
        que.pop();
        int val = *(idx.first);
        if (std::next(idx.first) != idx.second) {
            que.push({std::next(idx.first),idx.second});
        }
        return val;
    }

    bool hasNext() {
        return que.size();
    }
    queue<pair<vector<int>::iterator,vector<int>::iterator>> que;
};