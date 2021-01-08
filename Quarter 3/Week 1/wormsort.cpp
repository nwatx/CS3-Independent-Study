#include <bits/stdc++.h>

using namespace std;

#define vt vector

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORE(i, a, b) for(int i = (a); i <= (b); i++)
#define F0R(i, a) for(int i = 0; i < (a); i++)
#define trav(a, x) for (auto& a : x)

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (!s.empty()) { setIn(s+".in"), setOut(s+".out"); }
}

struct UF {
    vt<int> e;
    UF(int n) : e(n, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

const int INF = 1e9+7;

int N, M;

struct Edge {
    int a, b, w;
};

int cows[(int)1e5+1];
Edge edges[(int)1e5+1];

bool check(int val) {
    UF uf(N);
    F0R(i, M) {
        if(edges[i].w >= val) uf.join(edges[i].a, edges[i].b);
    }
    
    FOR(i, 1, N+1) {
        if(!uf.sameSet(cows[i], i)) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    setIO("wormsort"); cin >> N >> M;

    FOR(i, 1, N+1) {
        cin >> cows[i];
    }

    F0R(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }

    int l = 0, r = INF;
    int ret = -1;

    while(l <= r) {
        int mid = (l + r)/2;
        if(check(mid)) {
            ret = max(ret, mid);
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    if(ret == INF) cout << -1;
    else cout << ret;
}