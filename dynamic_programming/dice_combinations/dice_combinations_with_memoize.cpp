#include <iostream>
#include<vector>
#include<map>
using namespace std;


long long getTheNumberOfCombinations(long long n, vector<long long>& dp){
    const long long mod = 1e9 + 7;
    if(n < 0) return 0;
    if(n == 0) return 1;

    if(dp[n] != -1) return dp[n];

    long long cnt = 0;
    for(int i = 1; i <= 6; i++){
        cnt = (cnt + getTheNumberOfCombinations(n - i, dp)) % mod;
    }
    return dp[n] = cnt;
}

int main(){
    long long n;
    cin >> n;
    vector<long long> dp(n+1, 0);
    dp[0] = 1;
    long long ans = getTheNumberOfCombinations(n, dp);
    cout << ans << endl;
}