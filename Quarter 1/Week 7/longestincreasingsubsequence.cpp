#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define vt vector

const int MAX_N = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
#define sz(x) (int)x.size()

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
}

int nums[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //setIO("");

    int ret = 1;

    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // naive solution O(n^2) -> does not run in time on CSES
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < i; j++) {
    //         if(nums[j] < nums[i]) {
    //             dp[i] = max(dp[i], dp[j]+1);
    //         }
    //     }
    // }
    // for(int i = 0; i < n; i++) {
    //     cout << dp[i] << " ";
    //     ret = max(ret, dp[i]);
    // }

    vt<int> dp;

    for(int a : nums) {
        int pos = lower_bound(dp.begin(), dp.end(), a) - dp.begin();

        if(pos == sz(dp)) {
            dp.push_back(a);
        } else {
            dp[pos] = a;
        }
    }

    cout << sz(dp);
}