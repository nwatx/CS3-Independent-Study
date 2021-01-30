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

int N, Q;

int L[100001];
int R[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    vector<char> v(N);
    F0R(i, N) cin >> v[i];

    L[0] = 1;

    char lowest = v[0];

    FOR(i, 1, N) {
        if(v[i] > v[i-1] || v[i] < lowest) { 
            L[i]++;
            if(v[i] < lowest) lowest = v[i];
        }
        L[i] += L[i-1];
    }

    reverse(v.begin(), v.end());

    R[0] = 1;
    lowest = v[0];

    FOR(i, 1, N) {
        if(v[i] > v[i-1] || v[i] < lowest) { 
            R[i]++;
            if(v[i] < lowest) lowest = v[i]; 
        }
        R[i] += R[i-1];
    }

    reverse(R, R+N);
    F0R(i, N) dbg(R[i]);

    F0R(i, Q) {
        int a, b; cin >> a >> b;
        int ret = 0;
        if(a != 1) ret += L[a-1];
        if(b != N) ret += R[b];
        dbg(L[a-1], R[b]);
        cout << ret << "\n";
    }
}