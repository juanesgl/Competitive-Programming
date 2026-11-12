#include <bits/stdc++.h>
using namespace std;

long long solve(priority_queue<long long, vector<long long>, greater<long long>>& pq) {

    long long tc = 0;

    while (pq.size() > 1) {
        long long f = pq.top();
        pq.pop();

        long long s = pq.top();
        pq.pop();

        long long add = f + s;
        tc += add;

        pq.push(add);
    }

    return tc;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while (cin >> n && n != 0) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (int i = 0; i < n; i++) {
            long long num;
            cin >> num;
            pq.push(num);
        }

        cout << solve(pq) << "\n";
    }

    return 0;
}

