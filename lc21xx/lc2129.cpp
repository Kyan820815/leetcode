//--- Q: 2129. Capitalize the Title

//--- method 1: record first index of last word
class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.size(), last = 0;
        for (int i = 0; i <= n; ++i) {
            if (i == n || title[i] == ' ') {
                if (i-last > 2) {
                    title[last] = title[last]^32;
                }
                last = i+1;
            } else {
                title[i] = tolower(title[i]);
            }
        }
        return title;
    }
};