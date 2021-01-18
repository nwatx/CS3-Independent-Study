#include <bits/stdc++.h>

using namespace std;

#define vt vector

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORE(i, a, b) for(int i = (a); i <= (b); i++)
#define F0R(i, a) for(int i = 0; i < (a); i++)
#define trav(a, x) for (auto& a : x)

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (!s.empty()) { setIn(s+".in"), setOut(s+".out"); }
}

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<pair<int, int>> customers;
    F0R(i, N) {
        int a, b; cin >> a >> b;
        customers.push_back({a, 1});
        customers.push_back({b + 1, -1});
    }

    sort(customers.begin(), customers.end());

    int curr = 0;
    int l = 0;
    vt<long long> pfx(2*N + 1); // prefix sum array
    vt<int> arr(2*N);

    F0R(i, 2*N) { // coordinate compression
        if(i == 0) { customers[i].first = 0; }
        else if(customers[i].first > curr) { l++; curr = customers[i].first; } // we move a pointer
        arr[l+1] += customers[i].second;
        // pfx[l+1] += customers[i].second; implementation without arr, merges all interval end and starts here
    }

    FOR(i, 1, 2*N+1) {
        pfx[i] = arr[i] + pfx[i-1];
        // pfx[i] += pfx[i-1]; implementation without arr
    }

    long long ret = 0;

    F0R(i, 2*N+1) ret = max(ret, pfx[i]); // find our maximum value
    cout << ret << "\n";
}