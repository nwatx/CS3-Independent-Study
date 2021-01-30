#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORE(i, a, b) for(int i = (a); i <= (b); i++)
#define F0R(i, a) for(int i = 0; i < (a); i++)
#define trav(a, x) for (auto& a : x)

int N, M;

const int INF = 1e9;

vector<int> gaps;

bool ck(int mid) {
    int mC = M;
    trav(a, gaps) {
        if(a > mid) mC -= (a + mid/2) / mid;
    }
    return mC >= 0;
}

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    setIn("angry.in");
    setOut("angry.out");

    cin >> N >> M;
    vector<int> v(N);
    F0R(i, N) cin >> v[i];
    sort(v.begin(), v.end());
    gaps.resize(N-1);
    FOR(i, 1, N) gaps[i-1] = v[i] - v[i-1];
    // F0R(i, N-1) cerr << gaps[i] << " ";

    int l = 1, r = INF;
    int ret = INF;
    while(l <= r) {
        int mid = (l + r) / 2;
        bool chk = ck(mid);
        if(chk) {
            r = mid - 1;
            ret = min(ret, mid);
        } else {
            l = mid + 1;
        }
    }

    cout << ret;
}