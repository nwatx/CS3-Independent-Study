#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e2 + 2;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
#define sz(x) (int)x.size()

vector<int> incoming(MAX_N);
vector<int> outgoing(MAX_N);

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
}

int main() {
    setIO("factory");
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        incoming[b]++;
        outgoing[a]++;
    }

    int ans = -1;

    for(int i = 1; i <= n; i++) {
        if(ans == -1 && incoming[i] > 0 && outgoing[i] == 0) {
            ans = i;
        }
        else if(ans != -1 && incoming[i] > 0 && outgoing[i] == 0) {
            ans = -1;
            break;
        }
    }

    cout << ans;
}