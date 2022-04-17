//--- Q: 0604. Design Compressed String Iterator

//--- method 1: list impl
class StringIterator {
public:
    StringIterator(string compressedString) {
        int n = compressedString.size(), cnt = 0;
        char last = compressedString[0];
        for (int i = 1; i <= n; ++i) {
            if (i == n || isalpha(compressedString[i])) {
                ll.push_back({last,cnt});
                cnt = 0;
                if (i < n) {
                    last = compressedString[i];
                }
            } else {
                cnt = cnt*10 + (compressedString[i]-'0');
            }
        }
    }
    
    char next() {
        if (!hasNext()) {
            return ' ';
        }
        char ch = ll.front().first;
        if (!--ll.front().second) {
            ll.pop_front();
        }
        return ch;
    }
    
    bool hasNext() {
        return ll.size();
    }
    list<pair<char,int>> ll;
};

//--- method 2: directly processing
class StringIterator {
public:
    StringIterator(string compressedString) {
        str = compressedString;
        cur = 0, sz = 0;
    }
    
    char next() {
        if (!hasNext()) {
            return ' ';
        }
        if (!sz) {
            ch = str[cur++];
            while (cur < str.size() && isdigit(str[cur])) {
                sz = sz*10 + (str[cur++]-'0');
            }
        }
        --sz;
        return ch;
    }
    
    bool hasNext() {
        return !(cur == str.size() && !sz);
    }
    string str;
    char ch;
    int cur, sz;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */