#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define vt vector
#define f first
#define s second

#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()

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

void solve(int t) {
    string a; cin >> a;
    vt<int> kickInd;
    vt<int> startInd;
    for(int i = 0; i <= a.length()-4; i++) {
        if(a.substr(i, 4) == "KICK") {
            kickInd.pb(i);
        }
    }

    for(int i = 0; i <= a.length()-5; i++) {
        if(a.substr(i, 5) == "START") {
            startInd.pb(i);
        }
    }

    // for(int i = 0; i < sz(startInd); i++) {
    //     cout << startInd[i];
    // }

    int ret = 0;

    for(int i = 0; i < sz(kickInd); i++) {
        for(int j = 0; j < sz(startInd); j++) {
            if(kickInd[i] < startInd[j]) {
                ret++;
            }
        }
    }

    cout << "Case #" << t << ": " << ret << "\n";
}

int main() {
    //setIO("");

    int t; cin >> t;

    for(int i = 1; i <= t; i++) solve(i);
}