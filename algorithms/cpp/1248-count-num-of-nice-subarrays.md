Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16


Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length

**思路：**

After replacing each even by zero and every odd by one can we use prefix sum to find answer ?

解法如  [560](https://github.com/rongweihe/LeetCode/blob/master/algorithms/cpp/560-subarray-sum-equals-k.md) 一样。

```c++
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        std::unordered_map<int, int> mp{{0,1}};
        if (nums.size() < k) { return 0; }
        for (int &e : nums) {
            sum += (e & 0x01);
            if (mp.find(sum - k) != mp.end()) {
                res += mp[sum - k];
            }
            mp[sum]++;
        }
        return res;
    }
};
```