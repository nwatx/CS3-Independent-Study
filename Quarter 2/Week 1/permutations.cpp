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
    
    if(t == 1) {
        cout << "1";
    } else if(t==4) {
        cout << "2 4 1 3";
    }
    else if(t < 5) {
        cout << "NO SOLUTION";
    } else {
        vt<int> ret;
        for(int i = t; i>=1; i-=2) {
            ret.pb(i);
        }
        
        for(int i = t-1; i>= 1; i-=2) {
            ret.pb(i);
        }

        for(int i = 0; i < sz(ret); i++) {
            if(i == 0) {
                cout << ret[i];
            } else {
                cout << " " << ret[i];
            }
        }
    }
}