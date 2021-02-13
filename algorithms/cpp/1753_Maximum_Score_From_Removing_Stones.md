### 思路一

尽量使最多的那一堆石子变得最少，这样就可以获得最大的分数。

- 如果较少的两堆石子数量之和小于另一堆，那么最大分数就是这两较小堆石子的数量和；

- 如果较少的两堆石子数量和大于等于另一堆，那么最大的那一堆一定可以被取完；
- 所以此时的最大分数 = 最大堆的石子数量+先取较小两堆直到它们的数量和等于最大堆数量时获得的分数

```java
public int maximumScore(int a, int b, int c) {
    int[] nums = {a, b, c};
    Arrays.sort(nums);
    if (nums[0] + nums[1] <= nums[2]) {
      return nums[0] + nums[1];
    }
    return maximumScore(nums[0] - 1, nums[1] - 1, nums[2]) + 1;
}
```

### 思路二

这题可以分类讨论，如果有一个堆的数量大于其余两个的和，那么无论如何三个堆都不可能为空。反之，三个堆都可以尽可能为空，如果总数为奇数，则三个堆总共剩一个，如果为偶数，则三个堆全为空。

```c++
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        if(a+b<=c) return a+b;
        else if(a+c<=b) return a+c;
        else if(b+c<=a) return b+c;
        return (a+b+c)/2;
    }
};
```


