//--- Q: 0414. Third Maximum Number

//--- method 1: use pointer to store value
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int *n1, *n2, *n3;
        n1 = n2 = n3 = nullptr;
        for (auto &num: nums) {
            if (n1 && *n1 == num || n2 && *n2 == num) {
                continue;
            }
            if (!n1 || *n1 < num) {
                n3 = n2;
                n2 = n1;
                n1 = &num;
            } else if (!n2 || *n2 < num) {
                n3 = n2;
                n2 = &num;
            } else if (!n3 || *n3 < num) {
                n3 = &num;
            }
        }
        return !n3 ? *n1 : *n3;
    }
};

//--- method 2: set
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (auto &num: nums) {
            s.insert(num);
            if (s.size() > 3) {
                s.erase(s.begin());
            }
        }
        return s.size() == 3 ? *s.begin() : *s.rbegin();
    }
};