//--- Q: 1348. Tweet Counts Per Frequency

//--- method 1: multiset
cclass TweetCounts {
public:
    TweetCounts() {
        diff["minute"] = 60;
        diff["hour"] = 3600;
        diff["day"] = 86400;
    }
    
    void recordTweet(string tweetName, int time) {
        map[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        auto pos = map[tweetName].lower_bound(startTime);
        vector<int> res;
        int time = startTime, block = diff[freq], i = 0;
        while (startTime + i*block <= endTime) {
            int cnt = 0;
            for(; pos != map[tweetName].end() && *pos < min(startTime+(i+1)*block, endTime+1); ++pos) {
                ++cnt;
            }
            ++i;
            res.push_back(cnt);
        }
        return res;
    }
    unordered_map<string, multiset<int>> map;
    unordered_map<string, int> diff;
};


//--- method 2: O(n) search
class TweetCounts {
public:
    TweetCounts() {
        diff["minute"] = 60;
        diff["hour"] = 3600;
        diff["day"] = 86400;
    }
    
    void recordTweet(string tweetName, int time) {
        map[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> res((endTime-startTime)/diff[freq]+1, 0);
        int d = diff[freq];
        
        for (auto &time : map[tweetName]) {
            if (time >= startTime && time <= endTime) {
                int pos = (time - startTime) / d;
                res[pos]++;
            }
        }
        return res;
    }
    unordered_map<string, vector<int>> map;
    unordered_map<string, int> diff;
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
