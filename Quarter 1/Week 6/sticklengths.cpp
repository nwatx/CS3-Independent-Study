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

vt<ll> sticks(MAX_N);
vt<int> freq(MAX_N);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n; cin >> n;
    ll avg = 0;

    for(int i = 0; i < n; i++) {
        cin >> sticks[i];
        avg += sticks[i];
        freq[sticks[i]]++;
    }

    avg /= n;
    if(freq[avg+1] > freq[avg]) {
        avg += 1;
    }
    
    ll ret = 0;
    for(int i = 0; i < n; i++) {
        ret += abs(avg-sticks[i]);
    }

    cout << ret;
    
}