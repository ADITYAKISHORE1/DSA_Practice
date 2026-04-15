class Twitter {
    int time;
    int follower[101][101];
    unordered_map<int, vector<pair<int, int>>> tweets;

   public:
    Twitter() {
        time = 0;
        for (int i = 0; i < 101; i++) follower[i][i] = 1;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        for (int u = 0; u < 101; u++) {
            if (follower[userId][u] == 0) continue;
            int sz = tweets[u].size();
            for (int t = sz - 1; t >= 0 && t >= sz - 10; t--) {
                pq.push(tweets[u][t]);
            }
        }
        int i = 0;
        while (!pq.empty() and i < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
            i++;
        }
        return ans;
    }

    void follow(int followerId, int followeeId) { follower[followerId][followeeId] = 1; }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) follower[followerId][followeeId] = 0;
    }
};
