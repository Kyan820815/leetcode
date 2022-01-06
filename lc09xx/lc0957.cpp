//--- Q: 0957. Prison Cells After N Days

//--- method 1: mod if have seen.
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int> ori;
        int idx = 0;
        while (idx < n) {
            ++idx;
            vector<int> cur(cells.size(), 0);
            for (int i = 1; i < cells.size()-1; ++i) {
                cur[i] = cells[i-1] == cells[i+1];
            }
            if (!ori.size()) {
                ori = cur;
            } else if (ori == cur) {
                n = (n-1)%(idx-1);
                idx = 0;
            }
            cells = cur;
        }
        return cells;
    }
};