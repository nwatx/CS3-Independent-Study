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

int N, T;

bool farm[101];

struct shake {
    int time, a, b;
    bool operator<(const shake& other) {
        return time < other.time;
    }
};

bool comp(shake a, shake b) {
    return a.time < b.time;
}

vt<shake> actions;

bool works(int start, int K) {
    bool inf[N+1]; memset(inf, 0, N+1);
    int shakes[N+1]; memset(shakes, 0, N+1);

    if(farm[start]) inf[start] = true;

    trav(act, actions) {
        if(inf[act.a] && shakes[act.a] < K) {
            inf[act.b] = true; shakes[act.a]++;
        }

        if(inf[act.b] && shakes[act.b] < K) {
            inf[act.a] = true; shakes[act.b]++;
        }
    }

    // FOR(i, 1, N+1) {
    //     cout << inf[i] << " " << farm[i] << "\n";
    // }
    
    FOR(i, 1, N+1) {
        if(inf[i] != farm[i]) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    setIO(""); cin >> N >> T;

    string cows; cin >> cows;

    FOR(i, 1, N+1) {
        if(cows[i-1] == '1') farm[i] = true;
        else farm[i] = false;
    }

    F0R(i, T) {
        int a, b, c; cin >> a >> b >> c;
        actions.pb({a,b,c});
    }

    sort(all(actions), comp);

    int retX = 0, retY = INF, retZ = 0;

    FOR(i, 1, N) {
        bool s = false;
        FOR(j, 1, N+2) {
            bool check = works(i, j);
            if(!check) continue;
            if(j == N+1) { retZ = INF; }
            else retZ = max(retZ, j);

            retY = min(j, retY);
            s = true;
        }
        if(s) retX++;
    }

    if(retZ == INF) {
        cout << retX << " " << retY << " Infinity";
    } else {
        cout << retX << " " << retY << " " << retZ;
    }
    //cout << works(1, 2);
}