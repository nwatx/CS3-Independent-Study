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

set<int> A[26];
int L[100001];
int R[100001];
int pfx[100001];
bool tog[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    F0R(i, N) {
        char b; cin >> b;
        A[b - 'A'].insert(i);
    }

    F0R(i, 26) {
        if(!A[i].size()) continue;
        vector<int> tpPfx(N);
        tpPfx[*A[i].begin()]++;
        bool flag = false;
        FOR(j, *A[i].begin()+1, N) {
            if(flag && A[i].find(j) != A[i].end()) { tpPfx[j]++; flag = false; }
            else if(pfx[j]) flag = true;
        }

        FOR(j, 1, N+1) tpPfx[j] += tpPfx[j-1];
        FOR(j, 1, N+1) pfx[j] += tpPfx[j];
        F0R(i, N) {
            cout << tpPfx[i] << " ";
        }
        cout << "\n";
    }

}