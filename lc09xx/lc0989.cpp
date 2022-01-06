//--- Q: 0989. Add to Array-Form of Integer

//--- method 1: string processing
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        string kstr = to_string(k);
        int i = num.size()-1, j = kstr.size()-1;
        vector<int> res(num.size()+kstr.size()+1, 0);
        int carry = 0, idx = res.size()-1;
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) {
                carry += num[i--];
            }
            if (j >= 0) {
                carry += (kstr[j--]-'0');
            }
            res[idx--] = carry%10;
            carry /= 10;
        }
        return vector<int>(res.begin()+idx+1, res.end());
    }
};

//--- method 2: linear processing
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        for (int i = num.size()-1; i >= 0 && k; --i) {
            int now = k+num[i];
            num[i] = now%10;
            k = now/10;
        }
        while (k) {
            num.insert(num.begin(), k%10);
            k /= 10;
        }
        return num;
    }
};

//--- method 3: linked list
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        list<int> ll(num.begin(), num.end());
        auto it = prev(ll.end());
        while (k) {
            int now = k+*it;
            *it = now%10;
            k = now/10;
            if (it != ll.begin()) {
                it = prev(it);
            } else {
                break;
            }
        }
        while (k) {
            ll.push_front(k%10);
            k /= 10;
        }
        return vector<int>(ll.begin(),ll.end());
    }
};