#include <iostream>
#include <vector>
#include<unordered_map>
#include<unordered_set>
#include <climits>
#include <algorithm>
#include <string>
#define ll long long

using namespace std;


int editDistance(int i, int j, int n, int m, string& a, string& b, vector<vector<int>>& dp){

    if(i == n && j == m) return 0;
    
    if(i == n) return m - j; // need to insert remaining chars of b
    if(j == m) return n - i; // need to insert remaining chars of a

    if(dp[i][j] != -1) return dp[i][j];

    if(a[i] == b[j]) return dp[i][j] = editDistance(i+1, j+1,n, m, a, b, dp);
    return dp[i][j] = min({
            editDistance(i+1, j, n, m, a, b, dp) + 1, // add in A
            editDistance(i, j+1, n, m, a, b, dp) + 1, // add in B
            editDistance(i+1, j+1, n, m, a, b, dp) + 1 // replace in A and B
        });
}

int main(){
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    int d = editDistance(0, 0, n, m, a, b, dp);
    cout << d << endl;
}