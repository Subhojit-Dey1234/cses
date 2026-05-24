#include <iostream>
#include<vector>
#include<map>
#include <climits>
using namespace std;

int main(){
    long long n, target;
    cin >> n >> target;
    vector<long long> coins(n);
    vector<long long> dp(target + 1, LLONG_MAX);
    for(long long &c : coins) cin >> c;
    dp[0] = 0;
    for(long long t = 1; t <= target; t ++){
        for(long long i = 0; i < n; i++){
            if(t - coins[i] < 0) continue;
            long long d = dp[t - coins[i]];
            if(d != LLONG_MAX) d++;
            dp[t] = min(dp[t], d);
        }
    }

    if(dp[target] == LLONG_MAX) cout << -1 << endl;
    else cout << dp[target] << endl;
}