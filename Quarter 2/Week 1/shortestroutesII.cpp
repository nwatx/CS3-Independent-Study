#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define vt vector
#define f first
#define s second

typedef pair<int,int> pii;
typedef pair<long, long> pll;

#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define lb lower_bound
#define ub uppber_bound

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ll LINF = 1e18;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
}

ll adj[501][501];
ll dist[501][501];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //setIO("");
    for(int i = 0; i < 501; i++) {
        for(int j = 0; j < 501; j++) {
            dist[i][j] = -1;
        }
    }

    int N, M, Q; cin >> N >> M >> Q;
    for(int i = 0; i < M; i++) {
        ll a, b, c; cin >> a >> b >> c;
        if(adj[a][b] > 0) {
            adj[a][b] = min(adj[a][b], c);
            adj[b][a] = min(adj[b][a], c);
        } else {
            adj[a][b] = c;
            adj[b][a] = c;
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == j) dist[i][j] = 0;
            else if(adj[i][j]) dist[i][j] = adj[i][j];
            else dist[i][j] = INF;
        }
    }

    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i = 0; i < Q; i++) {
        int a, b; cin >> a >> b;
        if(dist[a][b] == INF) {
            cout << -1 << "\n";
        } else {
            cout << dist[a][b] << "\n";
        }
    }
}