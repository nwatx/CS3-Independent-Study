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
#define trav(a, x) for (auto& a : x)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<long, long> pl;
typedef pair<double, double> pd;

typedef vt<int> vi;
typedef vt<ld> vd;
typedef vt<ll> vl;
typedef vt<pi> vpi;
typedef vt<pl> vpl;

#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)

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

bool cmp(const pi& a, const pi& b) {
    return a.f < b.f;
}

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    setIO("lifeguards"); cin >> N;

    vpi guards;

    F0R(i, N) {
        int a, b; cin >> a >> b;
        guards.pb(mp(a,b));
    }

    sort(all(guards), cmp);

    int tot = 0, lhs = 0, rhs = 0;

    F0R(i, N) {
        if(guards[i].s > rhs) {
            lhs = max(rhs, guards[i].f);
            tot += guards[i].s - lhs;
            rhs = guards[i].s;
        }
    }

    int ret = tot;
    pi last;
    last.f = guards[N-1].s;
    guards.pb(last);
    rhs = 0;

    F0R(i, N) {
        int curr = min(guards[i+1].f, guards[i].s) - max(guards[i].f, rhs);
        ret = min(ret, curr);
        rhs = max(rhs, guards[i].s);
    }

    ret = max(ret, 0);

    cout << tot - ret;
}