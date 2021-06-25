//--- Q: 535. Encode and Decode TinyURL

//--- method 1: random pick index
class Solution {
public:
    string set = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        while (url2code.find(longUrl) == url2code.end()) {
            string code = "";
            for (int i = 0; i < 6; ++i) {
                char c = set[random()%set.size()];
                code.push_back(c);
            }
            if (code2url.find(code) == code2url.end()) {
                code2url[code] = longUrl;
                url2code[longUrl] = code;
            }
        }
        return "http://tinyurl.com/" + url2code[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string code = shortUrl.substr(19);
        return code2url[code];
    }
    unordered_map<string, string> url2code;
    unordered_map<string, string> code2url;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));