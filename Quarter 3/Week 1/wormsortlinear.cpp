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

struct Edge {
    int a, b, w;
};

bool comp(Edge a, Edge b) {
    return a.w > b.w;
}

int N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    setIO("wormsort"); 
    cin >> N >> M;
    vt<int> p(N+1);
    FOR(i, 1, N+1) {
        int a; cin >> a;
        p[i] = a;
    }

    int ret = -1;

    vt<Edge> w(M);

    F0R(i, M) {
        int a, b, c; cin >> a >> b >> c;
        w[i] = {a, b, c};
    }

    sort(w.begin(), w.end(), comp);

    UF uf(N);
    FOR(i, 1, N+1) {
        while(!uf.sameSet(i, p[i])) {
            ret++;
            uf.join(w[ret].a, w[ret].b);
        }
    }

    if(ret == -1) cout << -1;
    else cout << w[ret].w;
}