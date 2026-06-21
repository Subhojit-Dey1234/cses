#include <iostream>
#include <vector>
#include<unordered_map>
#include<unordered_set>
#include <climits>
#define ll long long

using namespace std;
const ll mod = 1e9 + 7;


ll f(ll i, ll prev, ll m, vector<ll>& v, vector<vector<ll>>& dp){
    if(i == (long long)v.size()){
        return 1l;
    }

    if(dp[i][prev] != -1) return dp[i][prev];
    if(v[i] != 0){
        if(i != 0 && abs(prev - v[i]) > 1) return dp[i][prev] = 0;
        return dp[i][prev] = f(i+1, v[i], m, v, dp);
    }

    ll cnt = 0l;
    for(ll x = 1; x <= m; x ++){
        if(i == 0 || abs(prev - x) <= 1){
            v[i] = x;
            cnt = (cnt + f(i+1, x, m, v, dp)) % mod;
            v[i] = 0;
        }
    }
    return dp[i][prev] = cnt;
}

int main(){
    ll n, m;
    cin >> n >> m;

    vector<ll> v(n);
    for(ll& x : v) cin >> x;

    vector<vector<ll>> dp(n, vector<ll>(m+1, 0));
    // dp[i][x] number of valid ways to fill positions [0...i] such that i has value x
    /*
    Base case i = 0
    if v[0] != 0 only x = v[0] is valid so dp[0][v[0]] = 1 all others are 0
    if v[0] == 0 any value 1..m is value so dp[0][x] = 1
    */
    if(v[0] == 0){
        for(ll x = 1; x <= m; x++) dp[0][x] = 1;
    }
    else dp[0][v[0]] = 1;

    for(ll i = 1; i < n; i++){
        for(ll x = 1; x <= m; x ++){
            if(v[i] != 0 && x != v[i]) dp[i][x] = 0; // 
            else{
                for(ll y = x-1; y <= x+1; y++){
                    if(y >= 1 && y <= m){
                        dp[i][x] = (dp[i][x] + dp[i-1][y]) % mod; // [ x - 1, x , x + 1 ] all are valid combinations
                    }
                }
            }
        }
    }

    ll cnt = 0;
    for(ll x = 1; x <= m; x ++) cnt = (cnt + dp[n-1][x])%mod; // count all the possible combination till the end of array
    cout << cnt << endl;
}