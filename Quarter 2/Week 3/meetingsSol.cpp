#include <bits/stdc++.h>

using namespace std;

#define ar array
#define vt vector
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define F0R(i, a) for(int i = 0; i < (a); i++)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long, long> pll;

#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const ld PI = 4*atan((ld)1);

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
}

int N, L;
vt<int> w, x, d;

int getTime() {
    vt<int> l, r;
    F0R(i, N) {
        if(d[i] == -1) l.pb(x[i]);
        else r.pb(x[i]);
    }
    vt<pair<int, int>> v;
    F0R(i, sz(l)) v.pb({l[i], w[i]});
    F0R(i, sz(r)) v.pb({L-r[i],w[sz(l)+i]});
    sort(beg(v), en(v));
    int tot = 0; for(auto& t : v) tot += t.s;
    for(auto& t : v) {
        tot -= 2*t.s;
        if(tot <= 0) return t.f;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    setIO("meetings");

    cin >> N >> L;

    F0R(i, N) {
        int a, b, c; cin >> a >> b >> c;
        w.pb(a); x.pb(b); d.pb(c);
    }

    vt<int> inds(N); iota(inds.begin(), inds.end(), 0);
    sort(beg(inds), en(inds), [](int a, int b) { return x[a] < x[b]; });
    vt<int> W, X, D;
    for(auto& t : inds) {
        W.pb(w[t]);
        X.pb(x[t]);
        D.pb(d[t]);
    }

    swap(w,W), swap(x, X), swap(d, D);

    queue<int> rig;
    int T = getTime();
    int ret = 0;

    F0R(i, N) {
        if(d[i] == -1) {
            while(sz(rig) && rig.front() + 2*T < x[i]) rig.pop();
            ret+=sz(rig);
        } else rig.push(x[i]);
    }
    cout << ret << "\n";
}