#include <iostream>
#include<vector>
#include<map>
#include <climits>
#define ll long long
using namespace std;


int main(){
    ll n, target;
    const ll mod = 1e9 + 7;
    cin >> n >> target;
    vector<ll> coins(n);
    vector<ll> dp(target + 1);
    for(ll &c : coins) cin >> c;
    dp[0] = 1;

    for(ll i = 0; i < coins.size(); i++){
        for(ll t = coins[i]; t <= target; t ++){
            if(t < coins[i]) continue;
            dp[t] = (dp[t] + dp[t - coins[i]])%mod;
        }
    }
    cout << dp[target] << endl;
}