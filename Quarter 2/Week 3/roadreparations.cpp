#include <bits/stdc++.h>

using namespace std;

#define ar array
#define vt vector
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define F0R(i, a) for(int i = 0; i < (a); i++)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long, long> pll;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const ld PI = 4*atan((ld)1);

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
}

int N, M;
int parent[MAX_N];
int ranks[MAX_N];

struct Edge {
    int u,v, w;
    bool operator<(Edge const& other) {
        return w<other.w;
    }
};

int find(int v) {
    if(parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if(a != b) {
        if(ranks[a] < ranks[b]) swap(a,b);
        parent[b] = a;
        if(ranks[a] == ranks[b]) ranks[a]++;
    }
}

vt<Edge> edges;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    setIO("");
    cin >> N >> M;

    F0R(i, MAX_N) parent[i] = i;

    F0R(i, M) {
        int a, b, c; cin >> a >> b >> c;
        edges.pb({a,b,c});
    }
    
    sort(beg(edges), en(edges));

    ll cost = 0;
    int uCount = N;

    for(Edge e : edges) {
        if(find(e.u) != find(e.v)) {
            cost += e.w;
            unite(e.u, e.v);
            uCount--;
        }
    }

    if(uCount == 1) {
        cout << cost;
    } else {
        cout << "IMPOSSIBLE";
    }
}