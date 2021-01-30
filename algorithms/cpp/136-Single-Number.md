```c++
class Solution {
public:
	int singleNumber(std::vector<int>& nums) {
		int ret = 0;
		for (auto &e: nums) ret ^= e;
		return ret;
	}
};
```

**复杂度分析**

- 时间复杂度：O(n)，其中 n是数组长度。只需要对数组遍历一次。
- 空间复杂度：O(1)。

