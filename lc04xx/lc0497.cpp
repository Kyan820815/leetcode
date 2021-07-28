//--- Q: 0497. Random Point in Non-overlapping Rectangles

//--- method 1: binary search + random point
class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        arrs = rects;
        sum = {(rects[0][2]-rects[0][0]+1)*(rects[0][3]-rects[0][1]+1)};
        for (int i = 1; i < rects.size(); ++i) {
            sum.push_back(sum.back()+(rects[i][2]-rects[i][0]+1)*(rects[i][3]-rects[i][1]+1));
        }
    }
    
    vector<int> pick() {
        int idx = random()%sum.back()+1;
        int left = 0, right = sum.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (sum[mid] < idx) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        int real_idx = (idx-1) - (left ? sum[left-1] : 0);
        int col = arrs[left][2]-arrs[left][0]+1;
        return {real_idx%col+arrs[left][0], real_idx/col+arrs[left][1]};
    }
    vector<vector<int>> arrs;
    vector<int> sum;
};

//--- method 2: resivoir sampling
class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        arrs = rects;
        sum = {(rects[0][2]-rects[0][0]+1)*(rects[0][3]-rects[0][1]+1)};
        for (int i = 1; i < rects.size(); ++i) {
            sum.push_back(sum.back()+(rects[i][2]-rects[i][0]+1)*(rects[i][3]-rects[i][1]+1));
        }
    }
    
    vector<int> pick() {
        int idx, farea, total = 0, i = 0;
        for (auto &arr: arrs) {
            int area = (arr[2]-arr[0]+1)*(arr[3]-arr[1]+1);
            total += area;
            if (random()%total < area) {
                idx = i, farea = area;
            }
            ++i;
        }
        int ridx = random()%farea;
        int col = arrs[idx][2]-arrs[idx][0]+1;
        return {ridx%col+arrs[idx][0], ridx/col+arrs[idx][1]};
    }
    vector<vector<int>> arrs;
    vector<int> sum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */