//--- Q: 0271. Encode and Decode Strings

//--- method 1: len(str) + '/' + str
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for (auto &str: strs) {
            res += to_string(str.size()) + "/" + str;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            int slashidx = s.find('/', i);
            int len = stoi(s.substr(i, slashidx-i));
            string str = s.substr(slashidx+1, len);
            res.push_back(str);
            i = slashidx+len+1;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));