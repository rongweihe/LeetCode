耗时 80 % 版：

```go
func checkSubarraySum(nums []int, k int) bool {
    sum := 0
    mp := map[int]int{}
    mp[0] = -1
    for i := 0; i< len(nums); i++ {
        sum += nums[i]
        if (k !=0) {
            sum %= k
        }
        if _, ok := mp[sum]; ok {
            if (i - mp[sum] > 1) {
                return true
            }
        } else {
            mp[sum] = i;
        }
    }
    return false
}
```

耗时 100% 版：

```go
func checkSubarraySum(nums []int, k int) bool {
  accSum := 0
  sumMap := map[int]int{0: -1}
  for i :=0; i< len(nums); i++ {
    accSum += nums[i]
    switch {
      case k > 0:
      	accSum %= k
      case k < 0:
      	accSum %= (-k)
    }
    if _, ok := sumMap[accSum]; !ok {
      sumMap[accSum] = i;
      continue;
    }
    if i - sumMap[accSum] >= 2 {
      return true
    }
  }
  return false
}
```

