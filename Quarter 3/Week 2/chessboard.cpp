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

int T;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while(T--) {
        int N;
        cin >> N;
        int tot = N*N;
        int inner = max(0, (N-2)*(N-2));
        int outer = tot - inner;

        cout << fixed;
        cout << setprecision(3);
        if(N == 1) cout << 0.0 << "\n";
        else cout << inner * sqrt(2) + outer << "\n";
    }
}