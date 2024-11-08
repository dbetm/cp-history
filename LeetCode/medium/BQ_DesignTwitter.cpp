#include <bits/stdc++.h>
// https://leetcode.com/problems/design-twitter/
// Tag(s): Implementation
using namespace std;

#define watch(x) cout << (#x) << " is " << x << endl;

struct User {
    string fullName;
    unordered_set<int> following;
    vector<pair<int, int>> tweets;
    User() : fullName("Anonymous") {}
};

class Twitter {
private:
    map<int, User*> users;
    int feedLength;
    long long int contID;

    void createUser(int userId) {
        if(this->users.find(userId) == this->users.end()) {
            this->users[userId] = new User();
            this->users[userId]->following.insert(userId);
        }
    }

    priority_queue<pair<int, int>> getRecentTweets(int userId) {
        this->createUser(userId);
        priority_queue<pair<int, int>> recentTweets;
        auto user = this->users[userId];

        // tweets by the user and
        // tweets by the users that the user is following
        for(const auto followeeId : user->following) {
            auto followee = this->users[followeeId];

            int cont = 0;
            int n = followee->tweets.size();
            while(cont < n and cont < this->feedLength) {
                recentTweets.push(followee->tweets[n - 1 - cont]);
                ++cont;
            }
        }

        return recentTweets;;
    }
public:
    Twitter(int feedLength=10) {
        this->feedLength = feedLength;
        this->contID = 0;
    }

    void postTweet(int userId, int tweetId) {
        this->createUser(userId);
        this->contID++;
        this->users[userId]->tweets.push_back({this->contID, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        priority_queue<pair<int, int>> recentTweets = getRecentTweets(userId);

        int cont = 0;
        while(!recentTweets.empty() and cont < this->feedLength) {
            feed.push_back(recentTweets.top().second);
            recentTweets.pop();
            ++cont;
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        this->createUser(followerId);
        this->createUser(followeeId);
        this->users[followerId]->following.insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        this->users[followerId]->following.erase(followeeId);
    }
};

void displayFeed(vector<int> &feed) {
    int n = feed.size();
    cout << "FEED" << endl;
    for (int i = 0; i < n; ++i) {
        cout << feed[i] << " ";
    }
    cout << endl;
}

int main() {
    Twitter twitter;

    twitter.postTweet(1, 5);
    auto feed = twitter.getNewsFeed(1);
    displayFeed(feed);
    twitter.follow(1, 2);
    twitter.postTweet(2, 6);
    auto feed2 = twitter.getNewsFeed(1);
    displayFeed(feed2);
    twitter.unfollow(1, 5);
    auto feed3 = twitter.getNewsFeed(1);
    displayFeed(feed3);

    return 0;
}
