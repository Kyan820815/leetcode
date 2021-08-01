//--- Q: 0575. Distribute Candies

//--- method 1: set
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> set;
        for (auto &type: candyType) {
            set.insert(type);
        }
        return min((int)set.size(), (int)candyType.size()/2);
    }
};

//--- method 2: sort then find # of kinds
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(), candyType.end());
        int types = 0;
        for (int i = 1; i <= candyType.size(); ++i) {
            types += (i == candyType.size() || candyType[i] != candyType[i-1]);
        }
        return min(types, (int)candyType.size()/2);
    }
};