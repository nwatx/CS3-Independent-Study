#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    map<int, int> m;
    for(int i = 0; i < n; i++) {
        //find(m.begin(), m.end(), v[i]) actually O(N) avoid this!
        if(m.find(v[i]) == m.end()) m[v[i]] = 0;
        if(i == 0) continue;
        if(v[i] != v[i-1]) {
            m[v[i]]++;
        }
    }

    for(auto& b : m) {
        if(v[n-1] != b.first) b.second++;
    }

    int ret = 1000000007;
    for(auto& b : m) {
        ret = min(ret, b.second);
    }

    cout << ret << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}