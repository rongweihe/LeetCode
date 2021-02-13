```go
func check(nums []int) bool {
    sum := 0
    for i := 0; i < len(nums); i++ {
        if nums[i] > nums[(i+1) % len(nums)] {
            sum++
        }
    }
    return sum<=1
}
```

