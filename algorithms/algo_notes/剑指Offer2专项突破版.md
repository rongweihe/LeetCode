[TOC]



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



## 【4】[剑指 Offer II 004. 只出现一次的数字 ](https://leetcode-cn.com/problems/WGki4K/)

给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。

 

示例 1：

输入：nums = [2,2,3,2]
输出：3
示例 2：

输入：nums = [0,1,0,1,0,1,100]
输出：100


提示：

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
nums 中，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次

【思路】

一个整数无非是由 32 个 0 和 1 组成的，那么我们可以将数组中所有数字的同一位置的数位相加。

将出现三次的数字单独拿出来，那么这些出现了三次的数字，任意的某一位数位置之和能被三整除

理解下面两句话：

因此如果数组中所有数字的第 i 位数位相加之和能被三整除，那么只出现一次的数字的第 i 数位一定是零。

相反，如果数组中所有数字的第 i 位数位相加之和能被三除余一，那么只出现一次的数的第 i 位数一定是 1

这样只出现一次的任意第 i 个数为可以由数组中所有数字的第 i 位数字和推算出来。

当我们知道了一个整数任意的某一位是 0 和 1 之后，也就知道了这个整数的数值。

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::vector<int> bitSum(32,0);
        for(int n : nums) {
            for (int i = 0; i < 32; ++i) {
                bitSum[i] += (n >> (31 - i)) & 1;
            }
        }
        int ret = 0;
        for(int i = 0; i < 32; ++i) {
            ret = (ret << 1) + bitSum[i] % 3;
        }
        return ret;
    }
};
```


举一反三
输入一个整数数组，数组中只有一个数字出现了 m 次，其他数字都出现了 n 次。请你找出那个唯一出现 m 的数字，那么假设 m 不能被 n 整除。

分析：这道题可以由第一道题举一反三而来，如果数组中所有数字的第 i 位数相加之和能被 n 整除，那么出现 m 次的数的第 i 数位一定是零，否则出现 m 次的数的第 i 位数一定是1。

 有一个 有限状态自动机 + 位运算 算法，这个后续看下。

## 【5】[318. 最大单词长度乘积](https://leetcode-cn.com/problems/maximum-product-of-word-lengths/)

【思路】

C++/位运算/巧妙的使用整数26位比特存储字母；用整数的二进制数位记录字符串中出现的字符；

int 整型数二进制有 32 位，题目要求只要 26 位就可以表示出一个字符串中出现的字符，因此可以用一个 int 型整数记录某个字符字符串出现的字符，如果字符串中包含 ‘a’ 则这个整数最右边数位 1 如果包含 ‘b’ 则字符串中倒数第二位数位 1，以此类推，这样的好处就是在预处理的时候就能快速判断两个数是否有相同的位数（位运算&）

时间复杂度  O(n*n)

```c++
class Solution {
public:
    int maxProduct(vector<string>& words) {
        std::vector<int> flags(words.size());
        for (int i = 0; i < words.size(); ++i) {
            for (char &c : words[i]) {
                flags[i] |= (1 << (c - 'a'));
            }
        }
        int ret = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if ((flags[i] & flags[j]) == 0) {
                    int prod = words[i].size()*words[j].size();
                    ret = max(ret, prod);
                }
            }
        }
        return ret;
    }
};
```



## 【6】[剑指 Offer II 006. 排序数组中两个数字之和](https://leetcode-cn.com/problems/kLl5u1/)

【思路】双指针

【代码】

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while( i < j && numbers[i] + numbers[j] != target) {
            if (numbers[i] + numbers[j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return {i,j};
    }
};
```

