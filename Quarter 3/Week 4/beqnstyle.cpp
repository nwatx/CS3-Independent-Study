#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORE(i, a, b) for(int i = (a); i <= (b); i++)
#define F0R(i, a) for(int i = 0; i < (a); i++)
#define trav(a, x) for (auto& a : x)

int N, Q;

const int MX = 2e5+5; // maximum N
const int MS = 18; // 18 is calculated by $\log_2 2e5$

int up[MS][MX]; 

vector<int> adj[MX]; // adjacency list

int jmp(int x, int d) {
    F0R(i, MS) if((d >> i) & 1) x = up[i][x];
    return x ?: -1; // modfication to return -1 if not found
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;

    FOR(i, 2, N+1) {
        int a; cin >> a;
        up[0][i] = a;
    }

    FOR(i, 1, 18) FOR(j, 1, N+1) up[i][j] = up[i-1][up[i-1][j]]; // construct our parent array

    // uncomment below if you want to see the parent array

    // F0R(i, MS) {
    //     FOR(j, 1, N+1) { // change this to the depth log_2(depth)
    //         cerr << setfill(' ') << setw(2) << up[i][j] << " ";
    //     }
    //     cerr << "\n";
    // }

    F0R(i, Q) {
        int a, b;
        cin >> a >> b;
        cout << jmp(a, b) << "\n";
    }
}