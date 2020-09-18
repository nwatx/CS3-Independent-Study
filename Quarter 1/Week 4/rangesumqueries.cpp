#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
#define sz(x) (int)x.size()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc; cin >> tc;
    int q; cin >> q;
    vector<ll> arr(tc+1);
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        ll a; cin >> a;
        arr[t] = arr[t-1] + a;
    }

    for(int i = 0; i < q; i++) {
        ll a,b; cin >> a >> b;
        cout << (arr[b]-arr[a-1]) << "\n";
    }
}