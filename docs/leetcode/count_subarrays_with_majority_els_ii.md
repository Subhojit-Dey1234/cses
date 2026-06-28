## Approach 1: Brute force with O(N^2) solution. Finding the target with two pointer approach.

```cpp
    if(nums[j] == target) count ++;
    else count --;
    if(count > 0) ans ++;
```

## Approach 2: Using prefix sum. If the (nums[i] == target) then +1 else -1

for example
```cpp
nums = [2, 2, 1, 1] target = 2;
changedNums = [1, 1, -1, -1]

then with O(N^2) approach if the sum > 0 then ans ++

(cummulativeSum[j] - cummulativeSum[i-1] > 0) then ans ++

```

## Optimal Approach 


```cpp
cummulativeSum[i-1] < cummulativeSum[j]

cummulativeSum[i-1] = cummulativeSum till i-1
cummulativeSum[j] = cummulativeSum till j
```

Core idea: Instead of scanning all past prefix sums, count how many of them are small enough.
You keep a counting array pre where pre[v] = "how many times has prefix sum v appeared so far."

For a given r, the answer contribution is: how many past prefix sums are strictly less than s[r+1]? That's just summing up 
`pre[0] + pre[1] + ... + pre[s[r+1]-1]`



```cpp
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        int cs = 0;
        mpp[cs] = 1;

        long long validLeft = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                // As the prefix Sum is increasing the number of sums less than the previousSums which are valid
                validLeft += (long long) mpp[cs]; 
                cs ++;
            }else{
                /*
                At any point, validLeft = how many past prefix sums are strictly less than cs?
                When prefix sum drops by 1, 
                the new question becomes: how many past prefix sums are strictly less than cs-1?

                When prefix sum drops, subarrays get weaker. Some left endpoints that previously formed a majority subarray no longer do. So we subtract them.
                */
                validLeft -= (long long) mpp[cs-1];
                cs --;
            }

            mpp[cs] ++;
            ans += validLeft;
        }

        return ans;
    }
};
```