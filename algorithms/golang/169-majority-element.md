```go
func majorityElement(nums []int) int {
    ret := nums[0]
    count := 1
    for i:=1; i<len(nums); i++ {
        if nums[i] != ret {
            count --
            if count == 0 {
                count = 1
                ret = nums[i]
            } 
        } else {
            count++
        }
    }
    return ret
}
```

