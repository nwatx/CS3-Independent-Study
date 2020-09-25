#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
#define sz(x) (int)x.size()

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
}

int main() {
    setIO("censor");
    string in; cin >> in;
    string rm; cin >> rm;
    for(int i = 0; i < in.size()-rm.size();) {
        if(in.substr(i, rm.size()).compare(rm) == 0) {
            //cout << in.substr(i, rm.size()) << endl;
            if(i < 0) i = 0;
            in.erase(i, rm.size());
            i -= rm.size();
        } else {
            i++;
        }
    }

    cout << in;
}