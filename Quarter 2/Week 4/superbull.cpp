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

vi teams;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N; cin >> N;

    F0R(i, N) {
        int a; cin >> a;
        teams.pb(a);
    }

    bool visited[N];

    int ret = 0;

    F0R(C, N) {
        int max = 0, maxI1 = -1, maxI2 = -1;
        int size = sz(teams);

        F0R(i, size) {
            if(visited[i]) continue;
            F0R(j, size) {
                if(i == j) continue;
                if(visited[j]) continue;

                int xo = teams[i] ^ teams[j];
                if(xo > max) {
                    max = xo; maxI1 = i; maxI2 = j;
                }
            }
        }

        cerr << maxI1 << " " << maxI2 << "\n";

        visited[maxI1] = true; visited[maxI2] = true;
        ret += max;
    }

    cout << ret;
}