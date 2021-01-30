Beats 100% 版：

```go
func hammingDistance(x int, y int) int {
    z := x ^ y
    num := 0
    for ; z !=0; z &= (z-1) {
        num ++
    }
    return num
}
```

