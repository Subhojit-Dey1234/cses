## Approach 1: Using Binary Search to find the split array

### Base Case

The lowest largest sum of an subarray is the `max(array)`
The highest largest sum of is `sum(array)`

### Logic

Find the number of `subarray` possible
- if less than K, decrease the higher one
- more than K, increase the lower one

```cpp
class Solution {
public:
    bool isTheNumberOfSubArraysLessThanK(vector<int>& nums, int k, int m){
        int numberOfSubArrays = 1;
        int s = 0;

        for(int x : nums){
            if(s + x > m){
                numberOfSubArrays ++;
                s = x;
            } else s += x;
        }

        return numberOfSubArrays <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = INT_MIN, h = 0;
        for(int x : nums) l = max(x, l), h += x;

        while(l <= h){
            int m = l + (h - l) / 2;
            if(isTheNumberOfSubArraysLessThanK(nums, k, m)) h = m - 1;
            else l = m + 1;
        }
        return l;
    }
};
```