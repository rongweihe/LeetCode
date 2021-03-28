**思路：前缀和 + 哈希表优化**

这道题和 [560](https://github.com/rongweihe/LeetCode/blob/master/algorithms/cpp/560-subarray-sum-equals-k.md) 是一致的，将所有的前缀和该前缀和出现的次数存到了 map 里。

只不过此题是计算和是给定 k 的倍数的情况。

在这种方法中，我们使用 HashMap 来保存到第 i 个元素为止的累积和，但我们对这个前缀和除以 k 取余数。原因如下：

我们遍历一遍给定的数组，记录到当前位置为止的 sum%k 。一旦我们找到新的 sum%k 的值（即在 HashMap 中没有这个值），我们就往 HashMap 中插入一条记录 (sum%k, i)。

现在，假设第 i 个位置的 sum%k 的值为 rem 。如果以 i 为左端点的任何子数组的和是 k 的倍数，比方说这个位置为 j ，那么 HashMap 中第 j 个元素保存的值为 (rem + n✖️k)%k，其中 n 是某个大于 0 的整数。我们会发现 (rem+n ✖️ k)%k=rem ，也就是跟第 i 个元素保存到 HashMap 中的值相同。

基于这一观察，我们得出结论：无论何时，只要 sum%k  的值已经被放入 HashMap 中了，代表着有两个索引 i 和 j ，它们之间元素的和是 k 的整数倍就可以直接返回。

下面的流程描述了数组 `nums: [2, 5, 33, 6, 7, 25, 15]` 且 `k=13` 的求解过程：

![](https://cdn.jsdelivr.net/gh/rongweihe/ImageHost01/images/leetcode523.png)

**复杂度分析**

时间复杂度： O(n) 。仅需要遍历 nums 数组一遍。

空间复杂度： O(min(n,k))。 HashMap 最多包含 min(n,k)个不同的元素。

```c++
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int size = nums.size();
        std::unordered_map<int, int> mp{{0,-1}};
        for (int i=0; i<size; ++i) {
            sum += nums[i];
            if (k != 0) {
                sum %=k;
            }
            if (mp.find(sum) != mp.end()) {
                if (i - mp[sum] > 1) {
                    return true;
                }
            }
            else {  mp[sum] = i; }
        }
        return false;
    }
};
```

