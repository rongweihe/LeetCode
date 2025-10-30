# 题目描述

link : https://leetcode.cn/problems/two-sum/description/?envType=problem-list-v2&envId=2ckc81c&  

给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

你可以按任意顺序返回答案。
 

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]
 

提示：

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案


# 解法

- map 映射，时间复杂度：O(N)

```go
func twoSum(nums []int, target int) []int {
    indexMap := make(map[int]int, 0)
    for i, v := range nums {
        need := target - v
        if _, ok := indexMap[need]; ok {
            return []int{indexMap[need], i}
        }
        indexMap[v] = i
    }
    return nil
}
```
