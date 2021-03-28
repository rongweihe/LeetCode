**思路：**

计算 `x` 和 `y` 之间的汉明距离，可以先计算 `x XOR y`，然后统计结果中等于 1 的位数即可。

##### 布赖恩·克尼根算法：该算法使用特定比特位和算术运算移除等于 1 的最右比特位

```c++
class Solution {
public:
    int hammingDistance(int x, int y) {
        return countNumOf1(x^y);
    }
    int countNumOf1(int d) {
        int num = 0;
        while(d) {
            num ++; 
            d &= (d-1);
        }
        return num;
    }
};
```

还可以利用现有的库函数。

比如 `C++`  可以直接调用

```c++
return bitset<32>(x^y).count();
```

`Python` 直接调用

```python
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        return bin(x ^ y).count('1')
```

`Java` 直接调用

```java
class Solution {
    public int hammingDistance(int x, int y) {
        return Integer.bitCount(x ^ y); 
    }
}
```

参考链接：https://leetcode-cn.com/problems/hamming-distance/solution/yi-ming-ju-chi-by-leetcode/