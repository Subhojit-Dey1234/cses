# Missing Number

**Problem:** You are given all numbers between 1, 2, ..., n except one. Find the missing number.

**Approach:** XOR all numbers 1..n, then XOR with all given numbers. The result is the missing number.

```cpp
#include <iostream>
using namespace std;

int main(){
    long long n;
    cin >> n;

    int x = 0;
    for(long long i = 1; i <= n; i++) x = x ^ i;
    n --;

    while(n --){
        long long a;
        cin >> a;
        x = x ^ a;
    }

    cout << x << endl;
}
```
