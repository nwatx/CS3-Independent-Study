#include <bits/stdc++.h>

using namespace std;

#define ar array
#define vt vector
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORE(i, a, b) for(int i = (a); i <= (b); i++)
#define F0R(i, a) for(int i = 0; i < (a); i++)
#define F0RE(i, a) for(int i = 0; i <= (a); i++)
#define F1RE(i, a) for(int i = 1; i <= (a); i++)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a, x) for (auto& a : x)

#define LSOne(S) ((S) & -(S))

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<long, long> pl;
typedef pair<double, double> pd;

typedef vt<int> vi;
typedef vt<ld> vd;
typedef vt<ll> vl;
typedef vt<pi> vpi;
typedef vt<pl> vpl;

#define pb push_back
#define mp make_pair
#define pf push_front
#define eb emplace_back
#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define sorr(x) sort(rall(x))

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const ld PI = acos((ld)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }

    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cerr << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        pr(first); pr(rest...); 
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr("{",x.f,", ",x.s,"}"); 
    }
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; // const needed for vector<bool>
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) { 
        pr(first); ps(); // no space at end of line
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...); // print w/ spaces
    }
}

using namespace output;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
}

int N, M, R;

typedef priority_queue<ll> pq;

int main() {
    clock_t chronos = clock();
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    setIO("rental"); cin >> N >> M >> R;

    vt<ll> cows(N, 0);
    set<ll> rentals;
    vt<pl> milks;

    F0R(i, N) {
        int a; cin >> a;
        cows[i] = a;
    }

    F0R(i, M) {
        int a, b; cin >> a >> b;
        milks.pb({b, a});
    }

    sorr(milks);
    sorr(cows);

    F0R(i, R) {
        int a; re(a);
        rentals.insert(a);
    }

    ll ret = 0;

    for(auto i = cows.begin(); i != cows.end();) {
        ll rC = 0, sC = 0;
        ll cap = *i;
        ll del = 0;
        auto edit = *milks.begin();
        ll eV = -1;

        cerr << "b: " << ret << " " << cap << " " << rC << " " << sC << "\n";

        if(!rentals.empty()) {
            rC = *rentals.rbegin();
        }

        if(!milks.empty()) {
            for(auto p = milks.begin(); p != milks.end(); p++) {
                if((p -> second) > cap) {
                    sC += (p -> first) * cap;
                    edit = *p;
                    eV = cap - (p -> second);
                    break;
                } else {
                    sC += (p -> first) * cap;
                    cap -= (p -> second);
                    del++;
                }
            }
        }

        cerr << cap << " rent " << rC << " milk: " << sC << "\n";

        if(rC == 0 && sC == 0) {
            break;
        } else if(sC >= rC) {
            ret += sC;
            cerr << "added (sC) " << *i << " with value: " << sC << "\n";
            //cerr << "A;LSDJFKAJSDLJFALKSJDFL;AJSD;JALKSJDF: " << del;
            milks.erase(milks.begin(), milks.begin() + del);
            if(eV != -1) {
                edit = mp(edit.f, eV);
            }
            i++;
            pr(milks);
        } else {
            ret += rC;
            cerr << "added " << *cows.rbegin() << " with value: " << rC << "\n";
            rentals.erase(*rentals.rbegin()); //erase the maximum value
            cows.pop_back(); //erase the smallest cow
        }
        //cerr << "a: " << ret << " " << cap << " " << rC << " " << sC << "\n";
    }
    
    cout << ret;
    cerr << ((double)((clock() - chronos)) / CLOCKS_PER_SEC);
}