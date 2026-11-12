#include <bits/stdc++.h>
using namespace std;


class MyDSU{

private:
    vector<int> parent;
    vector<int> sizee;
    int max_group;

public:
    MyDSU(int n){
        parent.resize(n + 1);
        sizee.resize(n + 1);
        max_group = 1;

        for (int i = 0; i <= n; i++){
            parent[i] = i;
            sizee[i] = 1;
        }
    }

        int find(int x){
            if (parent[x] == x){
                return x;
            }
            return parent[x] = find(parent[x]);
        }

        void unionSet(int x, int y){
            int rootX = find(x);
            int rootY = find(y);

            if (rootX != rootY){
                parent[rootX] = rootY;
                sizee[rootY] += sizee[rootX];

                if (sizee[rootY] > max_group){
                    max_group = sizee[rootY];
                }
            }
        }

        int getMax(){
            return max_group;
        }
};
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;


        MyDSU dsu(n);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            dsu.unionSet(u, v);
        }

        cout << dsu.getMax() << "\n";
    }

    return 0;
}
