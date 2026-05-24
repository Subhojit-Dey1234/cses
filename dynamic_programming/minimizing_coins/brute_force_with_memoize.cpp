#include <iostream>
#include<vector>
#include<map>
#include <climits>
using namespace std;

long long getTheMinimumNumberOfCoins(long long target, vector<long long>& coins, vector<long long>& dp){
    if(target < 0L) return LLONG_MAX;
    if(target == 0L) return 0;

    if(dp[target] != -1) return dp[target];

    long long ans = LLONG_MAX;
    for(long long i = 0; i < (long long)coins.size(); i++){
        long long numberOfWays = getTheMinimumNumberOfCoins(target - coins[i], coins, dp);
        if(numberOfWays != LLONG_MAX) numberOfWays ++;
        ans = min(ans, numberOfWays);
    }
    return dp[target] = ans;
}


int main(){
    long long n, target;
    cin >> n >> target;
    vector<long long> coins(n);
    vector<long long> dp(target + 1, -1);
    for(long long &c : coins) cin >> c;
    long long ans = getTheMinimumNumberOfCoins(target, coins, dp);

    if(ans == LLONG_MAX){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}