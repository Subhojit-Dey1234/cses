#include <iostream>
#include <vector>
#include<unordered_map>
#include<unordered_set>
#include <climits>
#include <algorithm>
#include <string>
#define ll long long

using namespace std;

int main(){
    ll n;
    cin >> n;
    ll total = (n * (n+1)) / 2;
    if(total%2){
        cout << 0 << endl;;
        return 0;
    }

    ll target = total/2;
    vector<vector<ll>> dp(n + 1, vector<ll>(target+1, 0));
    ll mod = 1e9 + 7;

    dp[0][0] = 1;
    for(ll x = 1; x <= n; x++){
        for(ll t = 1; t <= target; t ++){
            if(t < x) dp[x][t] = dp[x-1][t];
            else dp[x][t] = (dp[x-1][t - x] + dp[x-1][t]) % mod;
        }
    }

    cout << dp[n][target] << endl;
}