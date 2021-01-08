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

const int MX = 1e6;

int N, M;
int pfx[MX+1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    setIO("stacking");

    cin >> N >> M;

    F0R(i, M) {
        int a, b;
        cin >> a >> b;
        pfx[a]++;
        pfx[b+1]--;
    }

    FOR(i, 1, N+1) {
        pfx[i] += pfx[i-1];
    }

    sort(pfx, pfx + N + 1);
    FOR(i, 1, N+1) {
        cerr << pfx[i] << "\n";
    }
    cout << pfx[N/2];
}