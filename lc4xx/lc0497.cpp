//--- Q: 497. Random Point in Non-overlapping Rectangles

//--- method 1: binary search + random point
class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        int n = rects.size();
        w.resize(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            w[i] = w[i-1] + (rects[i-1][2]-rects[i-1][0]+1) 
                            * (rects[i-1][3]-rects[i-1][1]+1);
        }
        point = rects;
    }
    
    vector<int> pick() {
        int idx = rand() % w.back()+1;
        int left = 0, right = w.size()-1;
        while (left < right) {
            int mid = (right-left)/2 + left;
            if (w[mid] < idx) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        int weight = idx - w[left-1] - 1;
        int x = weight % (point[left-1][2]-point[left-1][0]+1) + point[left-1][0];
        int y = weight / (point[left-1][2]-point[left-1][0]+1) + point[left-1][1];
        return {x, y};
    }
    vector<int> w;
    vector<vector<int>> point;
};

//--- method 2: resivoir sampling
class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        point = rects;
    }
    
    vector<int> pick() {
        int sumarea = 0, select;
        for (int i = 0; i < point.size(); ++i) {
            int area = (point[i][2]-point[i][0]+1) * (point[i][3]-point[i][1]+1);
            sumarea += area;
            if (rand() % sumarea < area) {
                select = i;
            }
        }
        int x = rand() % (point[select][2]-point[select][0]+1) + point[select][0];
        int y = rand() % (point[select][3]-point[select][1]+1) + point[select][1];
        return {x, y};
    }
    vector<int> w;
    vector<vector<int>> point;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */