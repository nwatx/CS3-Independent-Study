#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e6 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
#define sz(x) (int)x.size()

vector<ll> dp(MAX_N);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n; cin >> n;

    dp[0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int x = 1; x <= 6; x++) {
            if(i-x >= 0) {
                dp[i] += dp[i-x];
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[n] << "\n";
}