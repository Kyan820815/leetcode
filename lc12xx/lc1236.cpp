//--- Q: 1236. Web Crawler

/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

//--- method 1: dfs recursion
class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        unordered_set<string> used;
        string host = extract(startUrl);
        dfs(startUrl, htmlParser, used, host);
        return vector<string>(used.begin(), used.end());
    }
    void dfs(string &now, HtmlParser &htmlParser, unordered_set<string> &used, string &host) {
        if (host == extract(now) && used.find(now) == used.end()) {
            used.insert(now);
            vector<string> getUrl = htmlParser.getUrls(now);
            for (int i = 0; i < getUrl.size(); ++i) {
                dfs(getUrl[i], htmlParser, used, host);
            }
        }
    }
    string extract(string &now) {
        string host = "";
        for (int i = 7; i < now.size(); ++i) {
            if (now[i] != '/') {
                host.push_back(now[i]);
            } else {
                break;
            }
        }
        return host;
    }
};