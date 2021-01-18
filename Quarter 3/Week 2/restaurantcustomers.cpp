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
    vt<pair<int, int>> customers;
    F0R(i, N) {
        int a, b;
        cin >> a >> b;
        customers.push_back({a, 1});
        customers.push_back({b + 1, -1});
    }

    vt<int> pfx((int)(customers.size())+1);

    sort(customers.begin(), customers.end());

    FOR(i, 1, (int)pfx.size()) {
        pfx[i] = customers[i-1].second + pfx[i-1];
    }

    int ret = 0;

    F0R(i, N) {
        cerr << pfx[i] << " ";
        ret = max(ret, pfx[i]);
    }

    cout << ret;
}