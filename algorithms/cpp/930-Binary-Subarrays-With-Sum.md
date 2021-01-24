**思路：前缀和 + 哈希表优化**

这道题和 [560](https://github.com/rongweihe/LeetCode/blob/master/algorithms/cpp/560-subarray-sum-equals-k.md) 是一致的，将所有的前缀和该前缀和出现的次数存到了 map 里。

**复杂度分析**

时间复杂度：O(n)，其中 n 为数组的长度。我们遍历数组的时间复杂度为 O(n)，中间利用哈希表查询删除的复杂度均为 O(1)，因此总时间复杂度为 O(n)。

空间复杂度：O(n)，其中 n 为数组的长度。哈希表在最坏情况下可能有 n 个不同的键值，因此需要 O(n) 的空间复杂度。

```c++
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int sum = 0, res = 0;
        int size = A.size();
        for (int i=0; i< size; ++i) {
            sum += A[i];
            if (mp.find(sum - S) != mp.end()) {
                res += mp[sum - S];
            }
            mp[sum] ++;
        }
        return res;
    }
};
```



**思路进阶**

