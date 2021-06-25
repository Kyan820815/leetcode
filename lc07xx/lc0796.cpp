//--- Q: 796. Rotate String

//--- method 1: inspect every char
class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.size() != B.size()) return false;
        else if (!A.size()) return true;
        for (int i = 0; i < A.size(); ++i)
        {
        	string tmp = A.substr(i+1, A.size()-i-1) + A.substr(0, i+1);
        	if (tmp == B) return true;
        }
        return false;
    }
};

//--- method 2: combine two A and check B in it
class Solution {
public:
    bool rotateString(string A, string B) {
        return (A.size() == B.size() && (A+A).find(B) != string::npos) ? true : false;
    }
};