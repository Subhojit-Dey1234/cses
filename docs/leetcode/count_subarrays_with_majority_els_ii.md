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
                validLeft += (long long) mpp[cs];
                cs ++;
            }else{
                cs --;
                validLeft -= (long long) mpp[cs];
            }

            mpp[cs] ++;
            ans += validLeft;
        }

        return ans;
    }
};
```