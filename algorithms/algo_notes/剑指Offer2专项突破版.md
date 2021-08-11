## 【1】[剑指 Offer II 001. 整数除法](https://leetcode-cn.com/problems/xoh6Oh/)

【思路】

见代码。

【参考代码】

```c++
//
class Solution {
  public int divide(int dividend, int divisor) {
    //-2^31/ -1 = 2^31 溢出
    if(dividend == 0x80000000 && divisor == -1){
        return 0x7FFFFFFF; 
    }

    int negative = 2;//用于记录正数个数
    //由于负数转为正数 -2^31 -> 2^31 越界，所以采用正数转为负数
    if(dividend > 0){
        negative --;
        dividend = -dividend;
    }

    if(divisor > 0){
        negative --;
        divisor = -divisor;
    }

    //计算两个负数相除
    int result = 0;
    while(dividend <= divisor){
        int value = divisor;//统计减数
        int quotient = 1;//统计商
        while(value > 0xc0000000 && value + value >= dividend){
            //value > 0xc0000000 防止value*2溢出
            quotient += quotient;//如果可以用乘法 quotient*=2
            value += value;//如果可以用乘法 value*=2
        }

        result += quotient;
        dividend -= value;
    }
    return negative == 1 ? -result : result;
}
}
```

## 【2】[剑指 Offer II 002. 二进制加法](https://leetcode-cn.com/problems/JFETK5/)

【思路】
双指针, 让两个数的末位对齐, 两个指针 i, j均从各自字符串的末尾开始走。

定义一个string res 来存放结果, 一个int carry来记录每位的进位值, 初始值设为0。
算当前位置的数时, sum = a[i] + b[j] + carry, 每趟都要记得更新carry的值。

循环结束时, 由于低位的数字字符先加到了结果字符串中, 最后还需要 reverse 一次, 让位置恢复正常。

【参考代码】

```c++
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        std::string ret;
        int carry = 0;
        while(i >= 0 || j>= 0) {
            int add1 = (i >= 0) ? a[i--] - '0': 0;//计算第一位
            int add2 = (j >= 0) ? b[j--] - '0': 0;//计算第二位
            int sum = add1 + add2 + carry;//计算和
            carry = (sum >= 2) ? 1 : 0; //计算进位
            sum = (sum >= 2) ? sum - 2 : sum;
            ret.append(std::to_string(sum));
        }
        if (carry == 1) ret.append("1");
        std::reverse(ret.begin(),ret.end());
        return ret;
    }
};
```

## 【3】[剑指 Offer II 003. 前 n 个数字二进制中 1 的个数](https://leetcode-cn.com/problems/w3tCBm/)

【思路】

**最常规解法 计算整数 i 的二进制**

1的个数有一种高效的解法是每次用 i&(i-1)将整数 i 的最右边的 1 变成 0 整数 i 减去 1 那么它最右边 1 变成 0，如果它的右边还有 0 则右边所有的 0 都变成 1,而其左边所有的位保持不变。下面对 i 和 i-1 进行位与运算，相当于将其最右边的 1 变成 0 。

以二进制的1100为例，它减去1的结果是1011 1100和1011的位与运算的结果正好是 1000 二进制的1100最右边的1变为0结果刚好就是 1000

```c++
class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> ret(n+1,0);
        for (int i = 0; i <=n; ++i) {
            int j = i;
            while(j) {
                ret[i]++;
                j = j & (j-1);
            }
        }
        return ret;
    }
};
```


如果一个整数共有 k 位，那么它的二进制形式中可能有 O(k) 个 1 在上述代码中，while 循环的代码对每个整数将执行 O(k)次，因此时间复杂度是 O(nk)

**利用 i&(i-1)计算**
根据前面的分析可知，i&(i-1)将 i 的二进制中最右边的 1 变成 0，也就是说，整数 i 的二进制形式 1 的个数比 i&(i-1) 的二进制形式 1 的个数多 1 利用这个性质有如下代码

```c++
class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> ret(n+1,0);
        for (int i = 1; i <=n; ++i) {
            ret[i] = ret[i & (i - 1)] + 1;
        }
        return ret;
    }
};
```


时间复杂度是 O(n)

**利用 i/2 计算**
还有没有更好的思路呢？

有的，如果正整数 i 是一个偶数，那么 i 相当于将 i/2 左移一位的结果，因此偶数 i 和 i/2 的二进制形式 1 的个数是一样的
如果 i 是奇数，那么 i 相当于将 i/2 左移一位之后再将最右边的位设为 1 的结果，因此奇数 i 比 i/2 的二进制形式 1 的个数多 1 个
可以利用这个规律有如下代码

```c++
class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> ret(n+1,0);
        for (int i = 0; i <=n; ++i) {
            ret[i] = ret[i >> 1] + (i & 1);//右移1位相当于i/2
        }
        return ret;
    }
};
```


时间复杂度是 O(n)。
