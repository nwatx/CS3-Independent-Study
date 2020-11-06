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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    setIO("lifeguards");

    
    int N; cin >> N;

    int start[N];
    int end[N];

    for(int i = 0; i < N; i++) {
        cin >> start[i]; cin >> end[i];
    }
    int result = 0;
    for(int i = 0; i < N; i++) {
        bool times[1001];
        F0R(j, 1001) times[j] = false;

        for(int j = 0; j < N; j++) {
            if(j!=i) {
                for(int k = start[j]; k < end[j]; k++) {
                    times[k] = true;
                }
            }
        }

        int ret = 0;

        F0R(j, 1001) {
            if(times[j]) ret++;
        }

        // F0R(j, 10) cout << times[j] << " ";
        // cout << "\n";
        result = max(result, ret);
    }
    cout << result;
}