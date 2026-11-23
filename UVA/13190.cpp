#include <bits/stdc++.h>
using namespace std;

using Med = tuple<long long, int, string, long long>;

using MinHeap = priority_queue<Med, vector<Med>, greater<Med>>;

void read_drugs(int m, MinHeap& pq){
    for (int i = 0; i < m; i++){
        string name;
        long long freq;
        cin >> name >> freq;
        pq.push ({freq, i, name, freq});
    }
}

void simulate(int k, MinHeap& pq){
    for(int i = 0; i < k; i++){
        long long ct;
        int idx;
        string name;
        long long freq;

        tie(ct, idx, name, freq) = pq.top();
        pq.pop();

        cout << ct << " " << name << "\n";
        pq.push({ct + freq, idx, name, freq});
    }
}

void solve_case(){
    int n, k;
    cin >> n >> k;
    MinHeap med_queue;

    read_drugs(n, med_queue);
    simulate(k, med_queue);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    if (cin >> t){
        while (t--){
            solve_case();
        }
    }
    return 0;
}
