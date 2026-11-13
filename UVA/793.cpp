#include <bits/stdc++.h>
using namespace std;

class MyDSU{
private:
    vector<int> parent;

public:
    MyDSU(int n){
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++){
            parent[i] = i;
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
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    string line;

    getline(cin, line);
    getline(cin, line);

    while(t--){
        getline(cin, line);

        int n = stoi(line);
        int succesful = 0;
        int unsuccesful = 0;
        MyDSU dsu(n);

        while (getline(cin, line) && line != ""){
            stringstream ss(line);
            char type;
            int c1, c2;

            ss >> type >> c1 >> c2;

            if (type == 'c'){
                dsu.unionSet(c1, c2);
            } else if (type == 'q') {
                if (dsu.find(c1) == dsu.find(c2)){
                    succesful++;
                } else{
                    unsuccesful++;
                }
            }
        }

        cout << succesful << "," << unsuccesful << "\n";

        if (t > 0) {
            cout << "\n";
        }
    }

    return 0;
}
