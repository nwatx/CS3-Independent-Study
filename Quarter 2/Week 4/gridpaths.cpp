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

string N;
int ret = 0;

string dS[] = {"U", "R", "L", "D"};
int dx[] = {0, 1, -1, 0};
int dy[] = {-1, 0, 0, -1};

bool matches(string a) {
    F0R(i, sz(a)) {
        //cout << a[i] << " " << N[i] << "\n";
        if(N[i] != '?' && a[i] != N[i]) return false;
    }
    return true;
}

void rec(string prev, int i, int j) {
    if(i < 0 || i >= 7 || j < 0 || j >= 7) return;
    if(!matches(prev)) return;
    if(sz(prev) == 48 && matches(prev) && i == 6 && j == 6) ret++;

    F0R(k, 2) {
        rec(prev + dS[k], i + dx[k], j + dx[k]);
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    setIO(""); cin >> N;

    rec("", 0, 0);
    cout << 2*ret;
}