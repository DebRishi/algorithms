#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;

class Twitter {
    public:

    class Tweet {
        public:
        int tweetId;
        int tweetTime;
        Tweet* next;

        Tweet(int id,int time) {
            tweetId = id;
            tweetTime = time;
            next = 0;
        }
    };

    class User {
        public:
        int userId;
        set<int> followed;
        Tweet* tweetHead;

        User(int id) {
            userId = id;
            followed.insert(id);
            tweetHead = 0;
        }

        void post(int id,int time) {
            Tweet* t = new Tweet(id,time);
            t->next = tweetHead;
            tweetHead = t;
        }

        void follow(int followeeId) {
            followed.insert(followeeId);
        }

        void unfollow(int followeeId) {
            followed.erase(followeeId);
        }

        vector<int> getFollowed() {
            vector<int> users;
            for(auto u : followed)
                users.push_back(u);
            return users;
        }
    };

    class compare {
        public:
        bool operator()(Tweet* a,Tweet* b) {
            return a->tweetTime < b->tweetTime;
        }
    };

    int timeStamp;
    map<int,User*> userMap;

    Twitter() {
        timeStamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        if(userMap.find(userId) == userMap.end()) {
            User* u = new User(userId);
            userMap[userId] = u;
        }
        userMap[userId]->post(tweetId,timeStamp++);
    }

    vector<int> getNewsFeed(int userId) {
        if(userMap.find(userId) == userMap.end())
            return {};

        vector<int> users = userMap[userId]->getFollowed();
        priority_queue<Tweet*,vector<Tweet*>,compare> heap;

        for(int user : users)
            if(userMap[user]->tweetHead)
                heap.push(userMap[user]->tweetHead);

        vector<int> feed;
        int n = 10;
        while(!heap.empty() && n-- > 0) {
            Tweet* t = heap.top();
            heap.pop();
            feed.push_back(t->tweetId);
            if(t->next)
                heap.push(t->next);
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        if(userMap.find(followerId) == userMap.end()) {
            User* u = new User(followerId);
            userMap[followerId] = u;
        }
        if(userMap.find(followeeId) == userMap.end()) {
            User* u = new User(followeeId);
            userMap[followeeId] = u;
        }
        userMap[followerId]->follow(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(userMap.find(followerId) == userMap.end() || userMap.find(followeeId) == userMap.end())
            return;
        userMap[followerId]->unfollow(followeeId);
    }
};

int main() {
    return 0;
}