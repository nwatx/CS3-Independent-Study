#include <bits/stdc++.h>

using namespace std;

#define ar array
#define vt vector
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define F0R(i, a) for(int i = 0; i < (a); i++)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long, long> pll;

#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
const int MAX_N = 5e4 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const ld PI = 4*atan((ld)1);

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
}

struct cow {
    int w, x, d;
};

int N, L;
deque<cow> pos;
int weights[MAX_N];

int lhs, rhs;

bool comp(cow a, cow b) {
    return a.x < b.x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    setIO("");
    cin >> N >> L;

    ll sum = 0;
    
    F0R(i, N) {
        int a, b, c; cin >> a >> b >> c;
        sum += a;
        pos.pb({a, b, c});
    }

    sum = (sum+1)/ 2;

    int time = 0;
    ll ret = 0;

    //cout << sum;

    // for(auto a : pos) {
    //     cerr << a.w << " " << a.x << " " << a.d << "\n";
    // }

    sort(beg(pos), en(pos), comp);

    while(lhs < sum && rhs < sum && sz(pos)) {
        //cout << "lhs: " << lhs << "rhs: " << rhs << "\n";

        // for(auto a : pos) {
        //     cout << a.w << " " << a.x << " " << a.d << "\n";
        // }
        
        if((sz(pos)>0) && pos[0].d == -1) {
            lhs += pos.front().w;
            pos.pop_front();
        }

        if((sz(pos)>0) && pos[sz(pos)-1].d == 1) {
            rhs += pos.back().w;
            pos.pop_back();
        }

        for(int i = 0; i < sz(pos)-1; i++) {
            if(pos[i].d == 1 && pos[i+1].d == -1) {
                swap(pos[i].d, pos[i+1].d);
                ret++;
                break;
            }
        }
    }

    cout << ret;    
}