#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
#define sz(x) (int)x.size()

bool found = false;

void floodfill(int i, int j, vector<vector<char>> &mat, vector<vector<bool>> &visited) {
    if(i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size()) return;
    visited[i][j] = true;
    if(mat[i][j] == '#') return;
    if(mat[i][j] == 'B') {
        found = true;
        return;
    }

    if(i+1 < sz(visited) && !visited[i+1][j]) { floodfill(i+1, j, mat, visited); }
    if(i-1 >= 0 && !visited[i-1][j]) { floodfill(i-1, j, mat, visited); }
    if(j+1 < sz(visited[0]) && !visited[i][j+1]) { floodfill(i, j+1, mat, visited); }
    if(j-1 >= 0 && !visited[i][j-1]) { floodfill(i, j-1, mat, visited); }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int r, c; cin >> r >> c;

    vector<vector<char>> maze(r, vector<char>(c));
    vector<vector<bool>> visited(r, vector<bool>(c));

    int x, y;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> maze[i][j];
            if(maze[i][j] == 'A') {
                x = i; y = j;
            }
        }
    }

    floodfill(x, y, maze, visited);
    cout << found;
}