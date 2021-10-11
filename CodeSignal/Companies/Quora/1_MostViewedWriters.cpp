#include <bits/stdc++.h>
// https://app.codesignal.com/company-challenges/quora/eSP6hZPxFkatRpjdp
// Tag(s): Implementation
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;

#define watch(x) cout << (#x) << " is " << x << endl;

bool compView(const vi &x, const int &y) {
    return x[0] < y;
}

void printVVI(const vvi &x) {
    int n = x.size();

    for (int i = 0; i < n; i++) {
        cout << "[";
        for(const auto &y : x[i]) {
            cout << y << ", ";
        }
        cout << "]" << endl;
    }
}

vvvi mostViewedWriters(vvi topicIds, vvi answerIds, vvi views) {
    vvvi ans;
    map<int, map<int, int>> topics; // *idTopic : [ *userd_id: views ]
    int numTopics = topicIds.size();

    sort(views.begin(), views.end());

    for (int q = 0; q < numTopics; q++) {
        //if(topicIds[q].size() == 0) continue;
        //else if(answerIds[q].size() == 0) continue;

        map<int, int> viewsPerUsers;

        for(const auto &answerId : answerIds[q]) {
            auto itIdx = lower_bound(views.begin(), views.end(), answerId, compView);
            int idx = (itIdx - views.begin());
            int userId = views[idx][1];
            int numViews = views[idx][2];

            if(viewsPerUsers.find(userId) != viewsPerUsers.end()) {
                viewsPerUsers[userId] += numViews;
            }
            else viewsPerUsers[userId] = numViews;
        }

        for (int x = 0; x < (int)topicIds[q].size(); x++) {
            int id = topicIds[q][x];

            if(topics.find(id) != topics.end()) {
                for(const auto &viewUser : viewsPerUsers) {
                    topics[id][viewUser.first] += viewUser.second;
                }
            }
            else {
                map<int, int> aux(viewsPerUsers);
                topics[id] = aux;
            }
        }
    }

    for(const auto &topic : topics) {
        vvi viewsPerTopic;

        for(const auto &user : topic.second) {
            viewsPerTopic.push_back({user.first, user.second});
        }
        sort(
            viewsPerTopic.rbegin(),
            viewsPerTopic.rend(),
            [&](const vi &x, const vi &y){
                if(x[1] == y[1]) return x[0] > y[0];

                return x[1] < y[1];
            }
        );

        ans.push_back(viewsPerTopic);
    }

    return ans;
}

int main() {
    int numQ, numIds, numAswers, numViews;
    cin >> numQ;
    vvi topicIds;

    for (int i = 0; i < numQ; i++) {
        cin >> numIds;
        vi ids(numIds);
        for (int j = 0; j < numIds; j++) cin >> ids[j];
        topicIds.push_back(ids);
    }

    // cout << "Topic IDs" << endl;
    // printVVI(topicIds);

    vvi answerIds;

    for (int i = 0; i < numQ; i++) {
        cin >> numAswers;
        vi ids(numAswers);
        for (int j = 0; j < numAswers; j++) cin >> ids[j];
        answerIds.push_back(ids);
    }

    // cout << "Answer IDs" << endl;
    // printVVI(answerIds);

    cin >> numViews;
    vvi views(numViews, vi(3));

    for (int i = 0; i < numViews; i++) {
        cin >> views[i][0];
        cin >> views[i][1];
        cin >> views[i][2];
    }

    // cout << "Views" << endl;
    // printVVI(views);

    auto popularWriters = mostViewedWriters(topicIds, answerIds, views);

    for(const auto &topic : popularWriters) {
        cout << '[';
        for(const auto &writer : topic) {
            cout << '[' << writer[0] << ", " << writer[1] << "],";
        }
        cout << ']' << endl;
    }

    return 0;
}
