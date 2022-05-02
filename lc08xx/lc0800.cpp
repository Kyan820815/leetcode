//--- Q: 0800. Similar RGB Color

//--- method 1: math processing
class Solution {
public:
    string similarRGB(string color) {
        for (int i = 1; i < color.size(); i+=2) {
            int v = stoi(color.substr(i,2), nullptr, 16);
            int idx = v/17 + (v%17 > 8 ? 1 : 0);
            color[i] = color[i+1] = idx < 10 ? idx+'0' : idx-10+'a';
        }
        return color;
    }
};