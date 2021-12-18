//--- Q: 1910. Remove All Occurrences of a Substring

//--- method 1: stack


//--- method 2: naive approach
class Solution {
public:
    string removeOccurrences(string s, string part) {
        for (int i = 0; i < s.size();) {
            if (i >= part.size()-1 && s.substr(i-part.size()+1, part.size()) == part) {
                s = s.substr(0, i-part.size()+1) + s.substr(i+1);
                i = i-part.size()+1;
            } else {
                ++i;
            }
        }
        return s;
    }
};