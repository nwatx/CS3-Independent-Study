#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define vt vector
#define f first
#define s second

typedef pair<int,int> pii;
typedef pair<long, long> pll;

#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define lb lower_bound
#define ub uppber_bound

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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    setIO("pairup");

    int t; cin >> t;
    vt<pii> cows(t);

    for(int i = 0; i < t; i++) {
        int a, b; cin >> a >> b;
        pii c = mp(b,a);
        cows[i] = c;
    }

    sort(cows.begin(), cows.end());

    // for(pii a : cows) {
    //     cout << a.f << " " << a.s << "\n";
    // }

    int lhs=0, rhs = t-1;
    int cmax = -INF;
    while(lhs <= rhs) {
        int l = cows[lhs].s;
        int r = cows[rhs].s;
        cmax = max(cmax, cows[lhs].f+cows[rhs].f);
        if(l-r>0) {
            cows[lhs].s -= cows[rhs].s;
            rhs--;
        } else if(r-l > 0) {
            cows[rhs].s -= cows[lhs].s;
            lhs++;
        } else {
            lhs++;
            rhs--;
        }
    }

    cout << cmax << "\n";
}