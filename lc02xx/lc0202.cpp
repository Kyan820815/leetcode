//--- Q: 0202. Happy Number

//--- method 1: slow and fast pointer
class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        while (1) {
            slow = findnext(slow);
            fast = findnext(findnext(fast));
            if (slow == fast) {
                break;
            }
        }
        return slow == 1;
    }
    int findnext(int n) {
        int val = 0;
        while (n) {
            int rem = n%10;
            n /= 10;
            val += rem*rem;
        }
        return val;
    }
}; 

//--- method 2: happy number will not be 4
class Solution {
public:
class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        while (n != 1 && n != 4) {
            int tmp = 0;
            while (n) {
                auto rem = n % 10;
                tmp += rem*rem;
                n /= 10;
            }
            n = tmp;
        }
        return n != 4;
    }
};