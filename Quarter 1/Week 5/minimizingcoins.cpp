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

vt<int> dp(MAX_N, INF);
vt<int> nums(101);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, max; cin >> n >> max;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for(int i = 1; i <= max; i++) {
        for(int num : nums) {
            if(i == num) { dp[i] = 1; }
            if(i+num < MAX_N) {
                dp[i+num] = min(dp[i+num], dp[i]+1);
            }
        }
    }

    dp[max] == INF ? cout << -1 : cout << dp[max];
}