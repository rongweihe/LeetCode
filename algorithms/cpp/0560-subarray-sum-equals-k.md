**思路：前缀和 + 哈希表优化**

这个题目和两数之和原理是一致的，只不过是将所有的前缀和该前缀和出现的次数存到了 map 里。

**复杂度分析**

时间复杂度：O(n)，其中 n 为数组的长度。我们遍历数组的时间复杂度为 O(n)，中间利用哈希表查询删除的复杂度均为 O(1)，因此总时间复杂度为 O(n)。

空间复杂度：O(n)，其中 n 为数组的长度。哈希表在最坏情况下可能有 n 个不同的键值，因此需要 O(n) 的空间复杂度。

```c++
class Solution {
public:
  int subarraySum(std::vector<int>& nums, int k) {
    int sum = 0, res = 0;
    std::unordered_map<int,int> mp{{0,1}};
    for (int &e : nums) {
      sum += e;
      res += mp[sum - k];
      mp[sum]++;
    }
    return res;
  }
};
```

