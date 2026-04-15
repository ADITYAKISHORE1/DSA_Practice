class Twitter {
    int time;
    unordered_map<int, unordered_set<int>> follower;
    unordered_map<int, vector<pair<int, int>>> tweets;

   public:
    Twitter() { time = 0; }

    void postTweet(int userId, int tweetId) { tweets[userId].push_back({time++, tweetId}); }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<tuple<int, int, int, int>> pq;
        follower[userId].insert(userId);
        for (auto u : follower[userId]) {
            int idx = tweets[u].size() - 1;
            if (idx >= 0) {
                auto [tim, twid] = tweets[u][idx];
                pq.push({tim, twid, u, idx});
            }
        }
        while (!pq.empty() and ans.size() < 10) {
            auto [tim, twid, u, idx] = pq.top();
            pq.pop();
            ans.push_back(twid);
            if (idx > 0) {
                auto [ti, tw] = tweets[u][idx - 1];
                pq.push({ti, tw, u, idx - 1});
            }
        }
        return ans;
    }

    void follow(int followerId, int followeeId) { follower[followerId].insert(followeeId); }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) follower[followerId].erase(followeeId);
    }
};
