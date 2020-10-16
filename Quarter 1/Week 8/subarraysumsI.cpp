#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define vt vector
#define f first
#define s second

#define mp make_pair
#define sz(x) (int)x.size()

const int MAX_N = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
}

int arr[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //setIO("");

    int t, x; cin >> t >> x;
    int sum = 0;

    for(int i = 0; i < t; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    int ret = 0;
    int lhs = 0, rhs = 0;

    for(int i = 0; i < t; i++) {
        if(lhs == rhs) {
            sum = arr[lhs];
        } else {
            sum = arr[lhs]+arr[rhs];
        }
        if(sum < x) {
            rhs++;
        } else if(sum > x) {
            lhs--;
        } else {
            ret++;
            
        }
    }


    cout << ret;
}