#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define vt vector

const int MAX_N = 1e3 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
#define sz(x) (int)x.size()

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
}

int cows[MAX_N];
int n = 0;

int sim(int position) {
    int ret = 0;
    for(int i = 0; i < n; i++) {
        ret += cows[(position + (i+1)) % n] * i;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    setIO("cbarn");

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> cows[i];
    }

    int ret = INF;

    for(int i = 0; i < n; i++) {
        ret = min(ret, sim(i));
    }

    cout << ret;
}