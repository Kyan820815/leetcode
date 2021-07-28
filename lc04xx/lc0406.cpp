//--- Q: 0406. Queue Reconstruction by Height

//--- method 1: build-in sort
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] > b[0] || a[0] == b[0] && a[1] < b[1];
        });
        list<vector<int>> ll;
        for (auto &person: people) {
            auto it = ll.begin();
            for (int i = 0; i < person[1]; ++i, ++it);
            ll.insert(it, person);
        }
        return vector<vector<int>>(ll.begin(), ll.end());
    }
};