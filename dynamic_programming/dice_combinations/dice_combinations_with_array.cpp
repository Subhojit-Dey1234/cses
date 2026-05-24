#include <iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    long long n;
    const long long mod = 1e9 + 7;
    cin >> n;
    vector<long long> dp(n+1, 0);
    dp[0] = 1;
    
    for(long long i = 1; i <= n; i++){
        for(long long dice = 1; dice <= 6; dice ++){
            if(i - dice >= 0) dp[i] = (dp[i] + dp[i - dice]) % mod;
        }
    }
    cout << dp[n] << endl;
}