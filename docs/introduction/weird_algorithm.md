# Weird Algorithm

**Problem:** Consider an algorithm that takes as input a positive integer n. If n is even, divide by 2. If n is odd, multiply by 3 and add 1. Repeat until n = 1. Print all values of n.

```cpp
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
```
