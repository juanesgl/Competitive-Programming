#include <bits/stdc++.h>
using namespace std;

vector<int> solve(const vector<pair<int, int>>& events, int k){

    unordered_map<int, int> qnum2period;
    for (const auto& p: events){
        qnum2period[p.first] = p.second;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (const auto& p: events) {
        pq.push({p.second, p.first});
    }

    vector<int> res;

    while(res.size() < k){
        int t = pq.top().first;
        int id = pq.top().second;
        pq.pop();

        res.push_back(id);

        pq.push({t + qnum2period[id], id});
    }

    return res;
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string word;
    vector<pair<int, int>> events;

    while (cin >> word && word != "#"){
        int id, period;

        cin >> id >> period;
        events.push_back({id, period});
    }

    int k;
    cin >> k;

    vector<int> r = solve(events, k);

    for (int e: r){
        cout << e << "\n";
    }

    return 0;
}
