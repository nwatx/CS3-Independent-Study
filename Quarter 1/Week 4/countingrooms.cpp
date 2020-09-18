#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
#define sz(x) (int)x.size()

void print2d(vector<vector<bool>> visited) {
    for (int i = 0; i < visited.size(); i++) 
    { 
        for (int j = 0; j < visited[i].size(); j++) 
        { 
            cout << visited[i][j] << " "; 
        }  
        cout << endl; 
    }
}

void floodfill(int i, int j, vector<vector<char>> &mat, vector<vector<bool>> &visited) {
    if(i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size()) return;
    visited[i][j] = true;
    if(mat[i][j] == '#') return;

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

    int l, w;
    cin >> l >> w;

    vector<vector<char>> mat(l, vector<char>(w));

    for(int i = 0; i < l; i++) {
        for(int j = 0; j < w; j++) {
            cin >> mat[i][j];
        }
    }

    vector<vector<bool>> visited(l, vector<bool>(w));

    int count = 0;

    for(int i = 0; i < l; i++) {
        for(int j = 0; j < w; j++) {
            if(!visited[i][j] && mat[i][j] != '#') {
                floodfill(i,j,mat,visited);
                count++;
            }
        }
    }

    cout << count;
}