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
const int MAX_N = 1e3 + 1;
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
int books[MAX_N];
int pages[MAX_N];
int dp[100001][MAX_N];
int N,X;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    setIO("");
    cin >> N >> X;

    F0R(i, N) cin >> books[i];
    F0R(i, N) cin >> pages[i];

    F0R(i, X+1) {
        F0R(j, N) {
            if(j == 0 && i >= books[j]) dp[i][j] = max(dp[i][j], pages[j]);
            else {
                if(i - books[j] >= 0) dp[i][j] = max(dp[i][j], dp[i-books[j]][j-1] + pages[j]);
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
        }
    }

    // F0R(i, X+1) {
    //     F0R(j,N) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << dp[X][N-1];
}