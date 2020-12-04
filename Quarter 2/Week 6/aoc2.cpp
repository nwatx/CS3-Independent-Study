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

    template<class T> void pr(const T& x) { cout << x; }
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

#define nl(x) cout << (x) << "\n";
#define nn << "\n";

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    setIn("aoc.in");

    string line = "";
    vi nums;

    vt<string> inS;
    vi inI;

    string curr = "";

    F0R(i, 1138) {
        getline(cin, line);
        if(line.empty()) {
            if(sz(curr)) inS.pb(curr);
            curr = " ";
        } else {
            curr += " " + line;
        }
        // inI.pb(stoi(line));
    }

    if(sz(curr)) inS.pb(curr);

    // pr(inS);

    int ret = 0;
    int check = 0;

    vt<string> params = {"byr:", "iyr:", "eyr:" , "hgt", "hcl", "ecl", "pid"};
    vt<string> eyeColors = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
    vt<string> pass;

    trav(a, inS) {
        int count = 0;
        F0R(i, sz(a)) {
            if(a[i] == ':') { count++; check++; }
        }

        // nl(count)

        if(count == 8 || (count == 7 && (a.find("cid") == string::npos))) {
            pass.pb(a);
            bool pass = true;
            F0R(i, 7) {
                if(i < 3) {
                    int num = stoi(a.substr(a.find(params[0]), 4));
                    if(i == 0) {
                        if(num < 1920 || num > 2002) pass = false;
                        break;
                    } else if(i == 1) {
                        if(num < 2010 || num > 2020) pass = false; break;
                    } else if(i == 2) {
                        if(num < 2020 || num > 2030) pass = false; break;
                    }
                } else if(i == 3) {
                    if(a.find("cm") != string::npos) {
                        int height = stoi(a.substr(a.find(params[3]), a.find("cm")));
                        if(height < 150 || height > 193) {
                            pass = false; break;
                        }
                    } else {
                        int height = stoi(a.substr(a.find(params[3]), a.find("in")));
                        if(height < 59 || height > 76) {
                            pass = false; break;
                        }
                    }
                } else if(i == 4) {
                    bool works = true;
                    F0R(i, 6) {
                        char curr = a[a.find(params[4]) + i + 1];
                        if(!((curr >= '0' && curr <= '9') || (curr >= 'a' && curr <= 'f'))) {
                            works = false; break;
                        }
                    }
                    pass = false; break;
                } else if(i == 5) {
                    string color = a.substr(a.find(params[4]), 3);
                    if(find(all(eyeColors), color) == eyeColors.end()) {
                        pass = false; break;
                    }
                } else if(i == 6) {
                    
                }
            }
        }
    }

//    pr(inS);
    trav(a, pass) {
        nl(a);
    }
}