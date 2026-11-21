#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 100000000
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n)-1) % (n))
#define INC(v, n) (v = ((v) + 1) % (n))
#define LOOP(i, ii, ff) for (int i = (ii); i < (ff); i++)
#define LSOne(i) ((i) & -(i))

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using pdd = pair<double, double>;
using vpdd = vector<pdd>;
using vii = vector<pii>;


struct Edge{
    double w; 
    int u, v;

    bool operator<(const Edge &other) const{
        return w < other.w;
    }
};


class MyDSU {
private:
    vi parent, sz;

public:
    MyDSU(int n): parent(n + 1), sz(n + 1, 1){
        LOOP(i, 0, n + 1){
            parent[i] = i;
        }
    }

    int find(int x){
        if (parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    bool unionSet(int x, int y){
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY){
            return false;
        }

        if (sz[rootX] < sz[rootY]){
            swap(rootX, rootY);
        }

        parent[rootY] = rootX;
        sz[rootX] += sz[rootY];
        return true;

    }
};

double dist(const pdd &a, const pdd &b) {
    double dx = b.F - a.F;
    double dy = b.S - a.S;
    return hypot(dx, dy);
}

double solve(const vpdd& freckles) {
    int n = static_cast<int>(freckles.size());
    vector<pair<double, pii>> edges;
    edges.reserve((n * (n - 1)) / 2);

    LOOP(i, 0, n) {
        LOOP(j, i + 1, n) {
            edges.PB({dist(freckles[i], freckles[j]), MP(i, j)});
        }
    }

    sort(edges.begin(), edges.end());

    MyDSU dsu(n);
    double cost = 0.0;
    int edges_used = 0;

    for (const auto& e : edges) {
        double w = e.F;
        int u = e.S.F;
        int v = e.S.S;
        if (dsu.unionSet(u, v)) {
            cost += w;
            edges_used++;
            if (edges_used == n - 1) {
                break;
            }
        }
    }

    return cost;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    int t; 
    
    if (!(cin >> t)) return 0; 

    LOOP(tc, 0, t){
        int n; 
        cin >> n; 

        vector<pair<double, double>> freckles(n); 

        LOOP(i, 0,n){
            cin >> freckles[i].F >> freckles[i].S;
        }

        if (tc> 0){
            cout << "\n";
        }
        cout << fixed << setprecision(2) << solve(freckles) << "\n";
        
    }

    return 0; 
}
