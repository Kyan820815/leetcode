//--- Q: 0535. Encode and Decode TinyURL

//--- method 1: random pick index
class Solution {
public:
    string code = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    // Encodes a URL to a shortened URL.
    unordered_map<string, string> long2short, short2long;
    string encode(string longUrl) {
        while (long2short.find(longUrl) == long2short.end()) {
            string shortUrl = "";
            while (shortUrl.size() < 6) {
                auto ch = code[random()%code.size()];
                shortUrl += ch;
            }
            if (short2long.find(shortUrl) == short2long.end()) {
                short2long[shortUrl] = longUrl;
                long2short[longUrl] = shortUrl;
                break;
            }
            shortUrl = "";
        }
        return "http://tinyurl.com/" + long2short[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return short2long[shortUrl.substr(19)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));