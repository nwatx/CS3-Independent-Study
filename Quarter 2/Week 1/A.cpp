#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define vt vector
#define f first
#define s second

typedef pair<int,int> pii;
typedef pair<long, long> pll;

#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define lb lower_bound
#define ub uppber_bound

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
    
    for(int i = 0; i < t; i++) {
        int n,m; cin >> n >> m;
        vt<int> arr(n);

        for(int i = 1; i <= n; i++) {
            cin >> arr[i-1];
        }

        int sum = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                sum += arr[j-1];
            }
        }

        bool ret = (sum == (m*n));
        if(ret) cout << "YES\n"; else cout << "NO\n";
    }
}