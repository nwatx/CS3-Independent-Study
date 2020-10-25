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

bool isPrime(int num){
    bool flag=true;
    for(int i = 2; i <= num / 2; i++) {
       if(num % i == 0) {
          flag = false;
          break;
       }
    }
    return flag;
}

int nextPrime(int N) 
{
    if (N <= 1) 
        return 2; 
  
    int prime = N; 
    bool found = false; 
  
    while (!found) { 
        prime++; 
  
        if (isPrime(prime)) 
            found = true; 
    } 
  
    return prime; 
} 

void primes(vector<int> &primes)  
{  
    bool IsPrime[100];  
    memset(IsPrime, true, sizeof(IsPrime));  
    
    for (int p = 2; p * p < 100; p++)  
    {  
        if (IsPrime[p] == true)  {
            for (int i = p * p; i <  100; i += p)  
                IsPrime[i] = false;  
        }  
    }  
    
    // Store all prime numbers  
    for (int p = 2; p < 100; p++)  
       if (IsPrime[p])  
            primes.push_back(p); 
             
}

void solve(int n) {
    int mat[n][n];
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1; j++) {
            mat[i][j] = 1;
        }
    }

    // nextPrime((n-1)*mat[n-1][0])-((n-1)*mat[n-1][0]);

    int num = 1;

    for(int i = 1; i <= 100; i++) {
        if(!isPrime(i) && isPrime((n-1)+i)) {
            num = i;
            break;
        }
    }

    for(int i = 0; i < n-1; i++) {
        mat[n-1][i] = num;
        mat[i][n-1] = num;
    }

    for(int i = 1; i<=100; i++) {
        if(!isPrime(i) && isPrime((n-1)*mat[0][n-1]+i)) {
            mat[n-1][n-1] = i;
            break;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(j == 0) cout << mat[i][j];
            else cout << " " << mat[i][j];
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //setIO("");

    int t; cin >> t;

    for(int i = 0; i < t; i++) {
        int a; cin >> a;
        solve(a);
    }
}