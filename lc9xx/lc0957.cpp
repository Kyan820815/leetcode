//--- Q: 957. Prison Cells After N Days

//--- method 1: mod if have seen.
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int i = 1;
        vector<int> last;
        while (i <= N) {
            vector<int> tmp(cells.size(), 0);
            for (int i = 1; i < cells.size()-1; ++i) {
                tmp[i] = cells[i-1] == cells[i+1];
            }
            cells = tmp;
            if (!last.size()) {
                last = cells;
            } else if (cells == last) {
                N = (N-1) % (i-1);
                i = 0;
            }
            ++i;
        }
        return cells;
    }
};