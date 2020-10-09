#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define vt vector
#define f first
#define s second

#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

char maze[1001][1001];
bool vis[1001][1001];
char pStep[1001][1001];

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
}

int r, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //setIO("");
    cin >> r >> c;

    pair<int, int> start;
    pair<int, int> end;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> maze[i][j];
            if(maze[i][j] == 'A') {
                start = mp(i, j);
            }

            if(maze[i][j] == 'B') {
                end = mp(i,j);
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(start);

    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    string step = "URDL";

    while(!q.empty()) {
        pair<int, int> curr = q.front(); q.pop();

        for(int i = 0; i < 4; i++) {
            pair<int, int> v = mp(curr.f + dx[i], curr.s + dy[i]);
            if(v.f < 0 || v.f >= r || v.s < 0 || v.s >= c) continue;
            if(maze[v.f][v.s] == '#') continue;
            if(vis[v.f][v.s]) continue;
            vis[v.f][v.s] = true;
            pStep[v.f][v.s] = step[i];
            q.push(mp(v.f, v.s));
        }
    }



    // for(int i = 0; i < r; i++) {
    //     for(int j = 0; j < c; j++) {
    //         cout << pStep[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // for(int i = 0; i < r; i++) {
    //     for(int j = 0; j < c; j++) {
    //         cout << vis[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    //cout << end.f << " " << end.s << "\n";

    if(vis[end.f][end.s]) {
        cout << "YES\n";
        vt<char> steps;
        while(end != start) {
            steps.pb(pStep[end.f][end.s]);
            end = mp(end.f- dx[step.find(pStep[end.f][end.s])], end.s - dy[step.find(pStep[end.f][end.s])]);
        }

        cout << sz(steps) << "\n";
        
        for(int i = sz(steps)-1; i >= 0; i--) {
            cout << steps[i];
        }
    } else {
        cout << "NO\n";
    }

}