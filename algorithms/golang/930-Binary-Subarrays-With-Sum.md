```go
func numSubarraysWithSum(A []int, S int)int {
  sum := 0
  res := 0
  sizeA := len(A)
  sumMap := make([]int, sizeA * 2 + 1)
  sumMap[sizeA] = 1
  for i := range A {
    sum += A[i]
    res += sumMap[sum - S + sizeA];
    sumMap[sum + sizeA] ++
  }
  return res
}
```

