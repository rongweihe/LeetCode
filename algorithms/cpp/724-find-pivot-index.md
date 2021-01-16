**思路**

先遍历一遍求出数组的和，然后第二次遍历时，直接进行对比左半部分和右半部分是否相同，如果相同则返回 true，不同则继续遍历。

**复杂度分析**

时间复杂度：O(n)，其中 n 为数组的长度。我们遍历数组的时间复杂度为 O(n)

空间复杂度：O(1)

```c++
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        for (auto &e : nums) {
            sum += e;
        }
        int leftSum = 0;
        for(int i=0; i<len; ++i) {
            if (leftSum == (sum - leftSum - nums[i])) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};
```