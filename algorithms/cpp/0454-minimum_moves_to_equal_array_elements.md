```c++
class Solution {
public:
    int minMoves(vector<int> &nums) {
        int moves;
        int numSize = nums.size();
        sort(nums.begin(), nums.end());
        long sum = 0;
        for (int i=1; i<numSize; ++i) {
            sum += nums[i];
        }
        moves = sum - (numSize - 1) * nums[0];
        return moves;
    }
};
```

### 思路

假设目前数组总和为`sum`，我们需要移动次数为`m`，那么整体数组总和将会增加`m * (n - 1)`，这里的`n`为数组长度，最后数组所有元素都相等为`x`，于是有：

`sum + m * (n - 1) = x * n  ` (1)。

我们再设数组最小的元素为`min_val`，`m = x - min_val`，即 `x = m + min_val`带入 (1) 得：

```c
m = sum - min_val * n
```

注意官网更新了 case 防止溢出。可以采用以下解法：

```c++
class Solution {
public:
	int minMoves(vector<int> &nums) {
        int moves = 0, min = INT_MAX;
        for (auto&e : nums) {
            min = std::min(min, e);
        }
        for (auto&e : nums) {
            moves += (e - min);
        }
        return moves;
    }
};
```

**复杂度分析**

- 时间复杂度：O(n)。一次遍历寻找最小值，一次遍历计算次数。
- 空间复杂度：O(1)。不需要额外空间。