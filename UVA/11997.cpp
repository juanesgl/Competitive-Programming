#include <bits/stdc++.h>
using namespace std;

vector<int> foundKSums(int k, vector<vector<int>>& arrays) {
    vector<int> L1 = arrays[0];

    for (int actual_k = 1; actual_k < k; actual_k++) {
        vector<int>& L2 = arrays[actual_k];

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < k; i++) {
            pq.push({L1[i] + L2[0], 0});
        }

        for (int i = 0; i < k; i++) {

            int val = pq.top().first;
            int pos = pq.top().second;
            pq.pop();

            L1[i] = val;

            if (pos + 1 < k) {
                pq.push({val - L2[pos] + L2[pos + 1], pos + 1});
            }
        }
    }

    return L1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;

    while (cin >> k) {
        vector<vector<int>> arrays(k, vector<int>(k));

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                cin >> arrays[i][j];
            }

            sort(arrays[i].begin(), arrays[i].end());
        }

        vector<int> res = foundKSums(k, arrays);

        for (int i = 0; i < k; i++) {
            cout << res[i] << (i == k - 1 ? "" : " ");
        }

        cout << "\n";
    }

    return 0;
}
