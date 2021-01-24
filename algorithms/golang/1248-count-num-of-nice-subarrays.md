**思路：**

After replacing each even by zero and every odd by one can we use prefix sum to find answer ?

解法如  [560](https://github.com/rongweihe/LeetCode/blob/master/algorithms/cpp/560-subarray-sum-equals-k.md) 一样。

```go
func numberOfSubarrays(nums []int, k int) int {
  sum, res := 0, 0
  size := len(nums)
  if (size < k) {return 0}
  mp := make([]int, size + 1)
  mp[0] = 1
  for i := range nums {
    sum += (nums[i] & 0x01)
    if sum - k >= 0 {
      res += vec[sum - k]
    }
    vec[sum]++
  }
  return res
}
```

