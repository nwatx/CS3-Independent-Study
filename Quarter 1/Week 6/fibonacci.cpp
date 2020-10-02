#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define vt vector

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
#define sz(x) (int)x.size()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n; cin >> n;

    ll a = 1, b = 1;
    bool lhs = true;

    for(ll i = 2 ; i <= n; i++) {
        if(lhs) {
            a = a + b;
            a %= MOD;
        } else {
            b = a + b;
            b %= MOD;
        }
        lhs = !lhs;
    }

    if(n == 0) {
        cout << 0 << "\n";
    }
    else if(lhs) {
        cout << a << "\n";
    } else {
        cout << b << "\n";
    }
}