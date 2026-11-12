#include <bits/stdc++.h>
using namespace std;

string solve(int TC) {
    queue<int> q;
    stack<int> s;
    priority_queue<int> pq;

    bool is_queue = true, is_stack = true, is_pq = true;

    for (int i = 0; i < TC; i++) {
        int x, y;
        cin >> x >> y;

        if (x == 1) {
            q.push(y);
            s.push(y);
            pq.push(y);
        }
        else if (x == 2) {
            if (q.empty() || s.empty() || pq.empty()) {
                is_queue = is_stack = is_pq = false;
            } else {
                if (q.front() != y) {
                    is_queue = false;
                }
                q.pop();

                if (s.top() != y) {
                    is_stack = false;
                }
                s.pop();

                if (pq.top() != y) {
                    is_pq = false;
                }
                pq.pop();
            }
        }
    }

    if (is_queue && !is_stack && !is_pq) {
        return "queue";
    } else if (is_pq && !is_queue && !is_stack) {
        return "priority queue";
    } else if (is_stack && !is_queue && !is_pq) {
        return "stack";
    } else if (!is_queue && !is_stack && !is_pq) {
        return "impossible";
    } else {
        return "not sure";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    while (cin >> TC) {
        cout << solve(TC) << "\n";
    }

    return 0;
}
