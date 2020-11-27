//--- Q: 1196. How Many Apples Can You Put into the Basket

//--- method 1: bucket sort
class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        vector<int> slot(1001, 0);
        int res = 0, sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            ++slot[arr[i]];
        }
        for (int i = 1; i <= 1000; ++i) {
            if (slot[i] > 0) {
                for (int j = 0; j < slot[i] && sum < 5000; ++j) {
                    sum += i;
                    ++res;
                }
            }
            if (sum >= 5000) {
                --res;
                break;
            }
        }
        return res;
    }
};