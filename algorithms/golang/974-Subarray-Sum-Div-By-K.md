```go
//同余定理：两个数模K的结果相等, 其差能被K整除
func subarraysDivByK(A []int, K int)int {
  sum , res := 0, 0
  mp := map[int]int{0:1}
  for i := range A {
    sum += A[i]
    mod := (sum%K + K) %K;
    if _, ok = mp[mod]; ok {
      res += mp[mod]
    }
    mp[mod]++
  }
  return res
}
```

简易版

```go
func subarraysDivByK(A []int, K int) int {
	sum ,res := 0, 0
	mp := make(map[int]int, K+1)
	mp[0] = 1
	for _, v := range A {
		sum += v
    mod := (sum%K + K) %K;
		res += mp[mod]
		mp[mod]++
	}
	return res
}
```

