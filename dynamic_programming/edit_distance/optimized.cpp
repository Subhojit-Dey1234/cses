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
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int j = 0; j <= m; j++) dp[0][j] = j; // base cases
    for(int i = 0; i <= n; i++) dp[i][0] = i; // base cases

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1});
        }
    }

    cout << dp[n][m] << endl;
}