#include <bits/stdc++.h>

using namespace std;

#define vt vector

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORE(i, a, b) for(int i = (a); i <= (b); i++)
#define F0R(i, a) for(int i = 0; i < (a); i++)
#define trav(a, x) for (auto& a : x)

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
    int i, j, w;
};

bool comp(Edge a, Edge b) {
    return a.w < b.w;
}

const int MX = 1000;

int N;
int x[MX];
int y[MX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    cin >> N;

    UF uf(N);

    F0R(i, N) {
        cin >> x[i];
        cin >> y[i];
    }

    vt<Edge> edges;

    F0R(i, N) {
        F0R(j, i) {
            int d = (x[i]-x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            edges.push_back({i, j, d});
        }
    }

    sort(edges.begin(), edges.end(), comp);

    int lastWeight = 0;
    int numComponents = N;

    trav(curr, edges) {
        if(!uf.sameSet(curr.i, curr.j)) {
            uf.join(curr.i, curr.j);
            lastWeight = curr.w;
            if(--numComponents == 1) {
                break;
            }
        }
    }

    cout << lastWeight;
}