#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define vt vector

const int MAX_N = 1e6 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
#define sz(x) (int)x.size()

vt<int> coins(100, 0);
vt<ll> dp(MAX_N, 0);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp[0] = 1;

    for(int j = 0; j < n; j++) {
        for(int i = 0; i <= m; i++) {
            if(i-coins[j] >= 0) {
                dp[i] += dp[i-coins[j]];
                dp[i] %= MOD;
            }
        }
    }

    // for(int i = 1; i <= m; i++) {
    //     cout << dp[i] << endl;
    // }

    cout << dp[m];
}