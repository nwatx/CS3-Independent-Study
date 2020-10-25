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
const int INF = 1e9;
const ll LINF = 1e18;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
}

int teams[MAX_N];
vt<int> graph[MAX_N];
bool visited[MAX_N];
bool possible = true;

void dfs(int node, int prev) {
    if(visited[node]) return;
    if(teams[node] != 0) return;
    if(!possible) return;
    visited[node] = true;
    if(prev == 1) {
        teams[node] = 2;
    } else if(prev == 2) {
        teams[node] = 1;
    }
    for(int a : graph[node]) {
        if(teams[node] == teams[a]) {
            possible = false;
            return;
        } else {
            dfs(a, prev);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //setIO("");

    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dfs(0, 1);

    if(!possible) { cout << "IMPOSSIBLE\n"; }
    else {
        for(int i = 0; i < n; i++) {
            cout << teams[i] << " ";
        }
    }
}