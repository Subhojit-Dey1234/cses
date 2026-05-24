#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<long long> ans;
    while(n != 1){
        ans.push_back(n);
        if(n%2 != 0) n = n*3 + 1;
        else if(n%2 == 0) n = n/2;
    }
    ans.push_back(n);
    for(long long x : ans) cout << x << " ";
}