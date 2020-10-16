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

    //setIO("");

    int t; cin >> t;

    vt<int> arr(t);
    for(int i = 0; i < t; i++) {
        cin >> arr[i];
    }

    map<int, int> last;

    int ret = 0;

    for(int i = 0, j = 0; i < t && j < t; i++) {
        if(!last.count(arr[i])) {
            last.insert(mp(arr[i], i));
        } else {
            j = max(j, last[arr[i]]+1);
            last[arr[i]] = i;
        }
        ret = max(ret, i - j + 1);
    }

    cout << ret;
}