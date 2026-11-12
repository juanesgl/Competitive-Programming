#include <bits/stdc++.h>
using namespace std;

bool adj[105][105]

void init_m(int n){
    for (int i = 1; i < n; i ++){
        for (int j = 1; j < n; j ++){
            adj[i][j] = false;
        }
    }
}

void graph(){
    int origin;
    while (cin >> origin && origin != 0){
        int destiny;

        while (cin >> destiny && destiny != 0){
            adj[origin][destiny] = true;
        }
    }
}

void floyd_warshall(int N){
    for (int k = 1; k <= N; k++){
        for(int j = 1; j <= N; j++){
            for (int x = 1; x <= N; x++){
                if (adj[i][k] == true && adj[k][j] == true){
                adj[i][j] = true;
            }
        }
    }
}

void process_queries(int N){
    int qt;
    cin >> qt;

    while (qt > 0){
        int start_node = 0;
        cin >> start_node;

        int cn = 0;
        vector<int> unreach;

        for (int i = 1; i <= N; i++){
            if (adj[start_node][i] == false){
                cn++:
                unreach.push_back(i);
            }
        }

        cout << cn;

        for (int node: unreach){
            cout << " " << node;
        }
        cout << "\n";

        qt--;
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    }

    return 0;
}
