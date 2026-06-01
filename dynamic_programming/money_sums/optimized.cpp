#include <iostream>
#include <vector>
#include<unordered_map>
#include<unordered_set>
#include <climits>
#include <algorithm>
#include <string>
#include <set>
#define ll long long
 
using namespace std;
 
int main(){
    ll n;
    cin >> n;
    vector<ll> coins(n);
    ll s = 0;
    for(ll &c : coins){
        cin >> c;
        s += c;
    }
    vector<vector<bool>> dp(n+1, vector<bool>(s+1, 0));
    /*
    Is it possible to make sum of j with i coins if dp[i][j] = 1;
    else not possible
    */
    dp[0][0] = 1;
    for(ll i = 1; i < n+1; i++){
        dp[i][i] = 1;
    }

    ll cnt = 0;
    for(ll i = 1; i < n+1; i++){
        for(ll t = 0; t < s+1; t++){
            dp[i][t] = dp[i-1][t];
            if((t - coins[i-1]) >= 0 && dp[i-1][t - coins[i-1]]) dp[i][t] = 1;

            if(i == n) cnt += dp[n][t];
        }
    }
    cout << (cnt - 1) << endl;
    for(ll j = 1; j < s+1; j ++){
        if(dp[n][j]) cout << j << " ";
    }
}
