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