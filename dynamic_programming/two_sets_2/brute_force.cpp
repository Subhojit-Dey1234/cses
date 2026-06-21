#include <iostream>
#include <vector>
#include<unordered_map>
#include<unordered_set>
#include <climits>
#include <algorithm>
#include <string>
#define ll long long

using namespace std;

ll f(ll x, ll n, ll total, vector<vector<ll>>& dp){
    const ll mod = 1e9 + 7;
    if(x > n) return 0;
    if(total < 0) return 0;
    if(total == 0) return 1;
    if(dp[x][total] != -1) return dp[x][total];
    return dp[x][total] = (f(x + 1, n, total - x, dp) + f(x + 1, n, total, dp))%mod;
}


int main(){
    ll n;
    cin >> n;
    ll total = (n * (n+1)) / 2;
    if(total%2){
        cout << 0 << endl;;
        return 0;
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(total/2 + 1, -1));
    ll cnt = f(1, n, total / 2, dp);
    cout << cnt << endl;
}