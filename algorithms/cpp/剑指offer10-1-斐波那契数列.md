写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：

输入：n = 2
输出：1
示例 2：

输入：n = 5
输出：5

### 思路一

递归，结果超时。

```c++
class Solution {
public:
    const int mod = 1e9+7;
    int fib(int n) {
        if (n <= 1) return n;
        return fib(n-1) + fib(n-2);
    }
};
```

### 思路二

动态规划。beats 100%。

动态规划：
原理： 以斐波那契数列性质 f(n + 1) = f(n) + f(n - 1)f(n+1)=f(n)+f(n−1) 为转移方程。
从计算效率、空间复杂度上看，动态规划是本题的最佳解法。

```c++
class Solution {
public:
    const int mod = 1e9+7;
    int fib(int n) {
        if (n<=1) return n;
        int f0 = 0, f1 = 1, sum = 0;
        for(int i = 2; i <= n; i++) {
            sum = (f0 + f1) % mod;
            f0 = f1;
            f1 = sum;
        }
        return sum;
    }
};
```

