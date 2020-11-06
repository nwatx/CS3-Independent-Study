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

int N;
vt<string> pops[25];

bool check2(vt<string> a, vt<string> b) {
    for(string c : a) {
        if(find(beg(b), en(b), c) == en(b)) {
            return false;
        }
    }
    return true;
}

bool check(vt<string> a, vt<string> b) {
    if(sz(a) == 0 || sz(b) == 0) return true;
    //F0R(i, sz(a)) cout << a[i]; F0R(i, sz(b)) cout << b[i];

    bool ret = true;
    for(string c : a) {
        if(find(beg(b), en(b), c) != en(b)) {
            ret = false; break; 
        }
    }
    if(ret) return true;
    if(sz(a) == sz(b) && a != b) return false;
    return check2(a, b) || check2(b, a);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //setIO("evolution");

    cin >> N;

    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        F0R(j, a) {
            string b; cin >> b;
            pops[i].pb(b);
        }
    }

    for(int i = 0; i < 25; i++) {
        sort(pops[i].begin(), pops[i].end());
    }

    //cout << check(pops[0], pops[3]) << "\n";

    int ret = true;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!check(pops[i], pops[j])) {
                //cout << i << " " << j;
                ret = false; break;
            }
        }
    }

    ret ? (cout << "yes") : (cout << "no");
}