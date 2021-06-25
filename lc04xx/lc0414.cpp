//--- Q: 414. Third Maximum Number

//--- method 1: use pointer to store value
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int *a, *b, *c;
        a = b = c = NULL;
        for (int i = 0; i < nums.size(); ++i) {
            if (!a || nums[i] >= *a) {
                if (a && nums[i] > *a) {
                    c = b;
                    b = a;
                }
                a = &nums[i];
            } else if (!b || nums[i] >= *b) {
                if (b && nums[i] > *b) {
                    c = b;
                }
                b = &nums[i];
            } else if (!c || nums[i] >= *c) {
                c = &nums[i];
            }
        }
        return !c ? *a : *c;
    }
};

//--- method 2: set
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            s.insert(nums[i]);
            if (s.size() > 3) {
                s.erase(*s.begin());
            }
        }
        return s.size() == 3 ? *s.begin() : *s.rbegin();
    }
};