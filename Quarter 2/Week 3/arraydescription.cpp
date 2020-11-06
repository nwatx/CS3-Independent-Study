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

int arr[MAX_N];
int N, M;
ll dp[MAX_N][101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    setIO("");
    cin >> N >> M;
    F0R(i, N) cin >> arr[i];
    
    if(arr[0] == 0) {
        FOR(i, 1, M+1) { dp[0][i] = 1; }
    }
    else dp[0][arr[0]] = 1;

    FOR(i, 1, N) {
        if(arr[i] == 0) {
            for(int j = 1; j <= M; j++) {
                if(j-1 >= 0) dp[i][j] += dp[i-1][j-1] % MOD;
                if(j+1 <= M) dp[i][j] += dp[i-1][j+1] % MOD;
                dp[i][j] += dp[i-1][j] % MOD;
            }
        } else {
            if(arr[i]-1 >= 0) dp[i][arr[i]] += dp[i-1][arr[i]-1] % MOD;
            if(arr[i]+1 <= M) dp[i][arr[i]] += dp[i-1][arr[i]+1] % MOD;
            dp[i][arr[i]] += dp[i-1][arr[i]] % MOD;
        }
    }

    // F0R(i, 10) {
    //     F0R(j, 10) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    ll res = 0;

    if(!arr[N-1]) {
        F0R(i, 101) {
            res += dp[N-1][i] % MOD;
        }
    } else {
        res = dp[N-1][arr[N-1]] % MOD;
    }
    
    cout << res % MOD;
}