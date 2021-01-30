#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORE(i, a, b) for(int i = (a); i <= (b); i++)
#define F0R(i, a) for(int i = 0; i < (a); i++)
#define trav(a, x) for (auto& a : x)

int N, Q;

const int MX = 2e5+5;
const int MS = 18; // 18 is calculated by $\log_2 2e5$ but we can add padding to be safe

int up[MX][MS]; 

vector<int> adj[MX]; // adjacency list

void dfs(int v, int p) { // we keep track of the current node v and its parent p
    up[v][0] = p;

    FOR(i, 1, MS) {
        if(up[v][i-1] != -1) up[v][i] = up[up[v][i-1]][i-1]; // construction of our ancestor tree
    }

    for(int e : adj[v]) if(e != p) dfs(e, v); // standard tree dfs
}

int query(int v, int j) { // a is our vertex, and j is the jump we make
    for(int i = MS-1; i >= 0; i--) { // start at our max value
        if(j >= (1 << i)) return query(up[v][i], j - (1 << i));
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    FOR(i, 2, N+1) { // one based indexing
        int a; cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }

    dfs(1, -1); // start at parent 1 (our root)

    // uncomment below if you want to see the parent array

    // F0R(i, N) {
    //     F0R(j, 3) { // change this to the depth log_2(depth)
    //         cerr << setfill(' ') << setw(2) << up[i][j] << " ";
    //     }
    //     cerr << "\n";
    // }

    F0R(i, Q) {
        int a, b;
        cin >> a >> b;
        int ret = query(a, b);
        cout << ((ret) ? ret : -1) << "\n";
    }
}