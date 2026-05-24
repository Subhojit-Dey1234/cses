#include <iostream>
#include<vector>
#include<map>
#include <climits>
#define ll long long

using namespace std;

ll getTheNumberOfWays(ll target, vector<ll>& coins, vector<ll>& dp){
    const ll mod = 1e9 + 7;
    if(target == 0L) return 1;
    if(target < 0L) return -1;

    if(dp[target] != -1) return dp[target];
    
    ll ans = 0;
    for(ll i = 0; i < (ll) coins.size(); i ++){
        ll cnt = getTheNumberOfWays(target - coins[i], coins, dp);
        if(cnt >= 0) ans = (ans + cnt)%mod;
    }
    return dp[target] = ans;
}


int main(){
    ll n, target;
    cin >> n >> target;
    vector<ll> coins(n);
    vector<ll> dp(target + 1, -1);
    for(ll &c : coins) cin >> c;
    ll ans = getTheNumberOfWays(target, coins, dp);
    cout << ans << endl;
}