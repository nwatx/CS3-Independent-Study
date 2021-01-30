#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORE(i, a, b) for(int i = (a); i <= (b); i++)
#define F0R(i, a) for(int i = 0; i < (a); i++)
#define trav(a, x) for (auto& a : x)

void DBG() { cerr << "]" << endl; }
template<class T, class ...U> void DBG(const T& t, const U&... u) {
    cerr << t; if (sizeof...(u)) cerr << ", ";
    DBG(u...); }
#ifdef LOCAL // compile with -DLOCAL, chk -> fake assert
    #define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
    #define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
            << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
    #define dbg(...) 0
    #define chk(...) 0
#endif

int N, K;

const int mx = 2e5+5;

set<int> pos[mx];
int A[mx];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    F0R(i, N) {
        A[i] = i;
    }

    vector<pair<int, int>> edges(N);
    F0R(i, K) {
        int a, b; cin >> a >> b;
        edges[i] = {a, b};
    }

    F0R(t, K) {
        F0R(i, K) {
            int a = edges[i].first-1;
            int b=  edges[i].second-1;
            pos[A[a]].insert(a);
            pos[A[b]].insert(b);
            swap(A[a], A[b]);
            pos[A[a]].insert(a);
            pos[A[b]].insert(b);

            // F0R(i, N) cerr << A[i] << " ";
            // cerr << "\n";
        }
    }

    F0R(i, N) {
        cout << max(1, (int)pos[i].size()) << "\n";
    }
}