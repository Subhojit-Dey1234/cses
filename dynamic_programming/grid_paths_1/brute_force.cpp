#include <iostream>
#include <vector>
#include<unordered_map>
#include<unordered_set>
#include <climits>
#define ll long long

using namespace std;
const ll mod = 1e9 + 7;


ll f(ll i, ll j, ll n, vector<vector<char>>& grid, vector<vector<ll>>& dp){
    if(i < 0 || j < 0 || i >= n || j >= n || grid[i][j] == '*') return 0;
    if(i == n-1 && j == n-1) return 1;
    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] =  (f(i + 1, j, n, grid, dp) + f(i, j+1, n, grid, dp))%mod;
}

int main(){
    ll n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n, '.'));
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    
    for(ll i = 0; i < n; i ++) for(ll j = 0; j < n; j ++) cin >> grid[i][j];
    ll ans = f(0, 0, n, grid, dp);
    cout << ans << endl;
}