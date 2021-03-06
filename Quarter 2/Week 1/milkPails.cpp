#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define vt vector
#define f first
#define s second

#define mp make_pair
#define sz(x) (int)x.size()

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    setIO("pails");

    int x, y, m; cin >> x >> y >> m;

    int closest = -1;

    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) {
            int sum = i * x + j * y;
            if(sum <= m && (abs(m-sum) < abs(closest-m))) {
               closest = sum; 
            }
        }
    }

    cout << closest;
}